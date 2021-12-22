/*
 * Copyright (c) 2020 SixOctets Systems
 * Copyright 2021 NXP
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>
#include <stddef.h>
#include <errno.h>
#include <toolchain.h>
#include <porting.h>
#include <fsl_debug_console.h>
#include <EmbeddedTypes.h>

#include <bluetooth/bluetooth.h>
#include <bluetooth/conn.h>
#include <bluetooth/uuid.h>
#include <bluetooth/gatt.h>
#include <central_ht.h>
#include <bluetooth/services/hts.h>

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static int scan_start(void);

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define CONN_DEVICE 2
static struct bt_conn *default_conn[CONN_DEVICE];
static struct bt_uuid_16 uuid = BT_UUID_INIT_16(0);
static struct bt_gatt_discover_params discover_params[CONN_DEVICE];
static struct bt_gatt_subscribe_params subscribe_params[CONN_DEVICE];

static bool scan_req = 0;
static bool start_scanning = 0;

/*******************************************************************************
 * Code
 ******************************************************************************/
static uint8_t notify_func(struct bt_conn *conn,
               struct bt_gatt_subscribe_params *params,
               const void *data, uint16_t length)
{
    struct temp_measurement temp_measurement;
    uint32_t temperature;

    if (!data)
    {
        PRINTF("Unsubscribed \r\n");
        params->value_handle = 0U;
        return BT_GATT_ITER_STOP;
    }

    /* temperature value display */
    temp_measurement = *(struct temp_measurement*)data;
    temperature = sys_get_le32(temp_measurement.temperature);

    if ((temp_measurement.flags & BIT0) == hts_unit_celsius_c)
    {
        PRINTF("Temperature %d degrees Celsius \r\n", temperature);
    }
    else
    {
        PRINTF("Temperature %d degrees Fahrenheit \r\n", temperature);
    }
    if(scan_req == 1)
    {
    	//scan_start();
    	start_scanning = 1;
    	scan_req = 0;
    }

    return BT_GATT_ITER_CONTINUE;
}

static uint8_t discover_func(struct bt_conn *conn,
                 const struct bt_gatt_attr *attr,
                 struct bt_gatt_discover_params *params)
{
    int32_t err;

    if (!attr)
    {
        PRINTF("Discover complete, No attribute found \r\n");
        (void)memset(params, 0, sizeof(*params));
        scan_start();
        return BT_GATT_ITER_STOP;
    }
    for(uint32_t i=0; i<CONN_DEVICE; i++)
    {
    	if(conn == default_conn[i])
    	{
			if (bt_uuid_cmp(discover_params[i].uuid, BT_UUID_HTS) == 0)
			{
				/* Health Thermometer service discovered */
				memcpy(&uuid, BT_UUID_HTS_MEASUREMENT, sizeof(uuid));
				discover_params[i].uuid = &uuid.uuid;
				discover_params[i].start_handle = attr->handle + 1;
				discover_params[i].type = BT_GATT_DISCOVER_CHARACTERISTIC;

				err = bt_gatt_discover(conn, &discover_params[i]);
				if (err)
				{
					PRINTF("Discover failed (err %d)\r\n", err);
				}
			}
			else if (bt_uuid_cmp(discover_params[i].uuid, BT_UUID_HTS_MEASUREMENT) == 0)
			{
				/* Health Thermometer Measurement characteristic discovered */
				memcpy(&uuid, BT_UUID_GATT_CCC, sizeof(uuid));
				discover_params[i].uuid = &uuid.uuid;
				discover_params[i].start_handle = attr->handle + 2;
				discover_params[i].type = BT_GATT_DISCOVER_DESCRIPTOR;
				subscribe_params[i].value_handle = bt_gatt_attr_value_handle(attr);

				err = bt_gatt_discover(conn, &discover_params[i]);
				if (err)
				{
					PRINTF("Discover failed (err %d)\r\n", err);
				}
			}
			else
			{
				/* Subscribe to Health Thermometer service */
				subscribe_params[i].notify = notify_func;
				subscribe_params[i].value = BT_GATT_CCC_INDICATE;
				subscribe_params[i].ccc_handle = attr->handle;

				err = bt_gatt_subscribe(conn, &subscribe_params[i]);
				if (err && err != -EALREADY)
				{
					PRINTF("Subscribe failed (err %d)\r\n", err);
				}
				else
				{
					PRINTF("Subscribed to HTS%d\r\n",i);
//					scan_start();
				}
				return BT_GATT_ITER_STOP;
			}
			break;
    	}
    }

    return BT_GATT_ITER_STOP;
}

static void connected(struct bt_conn *conn, uint8_t conn_err)
{
    char addr[BT_ADDR_LE_STR_LEN];
    int32_t err;

    bt_addr_le_to_str(bt_conn_get_dst(conn), addr, sizeof(addr));

    if (conn_err)
    {
        PRINTF("Failed to connect to %s (err %u)\r\n", addr, conn_err);
        for(uint32_t i=0; i<CONN_DEVICE; i++)
        {
        	if (conn == default_conn[i])
        	{
				bt_conn_unref(default_conn[i]);
				memset(default_conn[i],0,sizeof(default_conn));
			//	default_conn[i] = NULL;
				break;
        	}
        }
        /* Restart scanning */
        scan_start();
        return;
    }

    PRINTF("Connected to peer: %s\r\n", addr);

    for(uint32_t i=0; i<CONN_DEVICE; i++)
    {
		if (conn == default_conn[i])
		{
			memcpy(&uuid, BT_UUID_HTS, sizeof(uuid));
			discover_params[i].uuid = &uuid.uuid;
			discover_params[i].func = discover_func;
			discover_params[i].start_handle = 0x0001;
			discover_params[i].end_handle = 0xffff;
			discover_params[i].type = BT_GATT_DISCOVER_PRIMARY;

			/* Start service discovery */
			err = bt_gatt_discover(default_conn[i], &discover_params[i]);
			if (err)
			{
				PRINTF("Discover failed(err %d)\r\n", err);
			}
			else
			{
				PRINTF("Starting service discovery %d \r\n",i);
			}
			break;
		}
    }
    if((default_conn[0]!=NULL)&&(default_conn[1]!=NULL))
    {
             PRINTF("Connected to 2 servers\r\n");
             scan_req = 0;
    }
    else
    {
 /*   	err = scan_start();
        if (err)
        {
            PRINTF("Scan Restrt: Scanning failed to start (err %d)\r\n", err);
            //scan_stop = 1;
        }
        else
        {
            PRINTF("Scanning started\r\n");
            //scan_stop = 0;
        }*/
    	scan_req = 1;
    }
}

static bool device_scanned(struct bt_data *data, void *user_data)
{
    bt_addr_le_t *addr = user_data;
    struct bt_uuid *uuid;
    uint16_t u16;
    int err;
    int i;
    bool continueParse = true;

    /* return true to continue parsing or false to stop parsing */
    switch (data->type)
    {
        case BT_DATA_UUID16_SOME:
        case BT_DATA_UUID16_ALL:
        {
            if (data->data_len % sizeof(uint16_t) != 0U)
            {
                PRINTF("AD malformed\r\n");
                return true;
            }

            for (i = 0; i < data->data_len; i += sizeof(uint16_t))
            {
                memcpy(&u16, &data->data[i], sizeof(u16));
                uuid = BT_UUID_DECLARE_16(sys_le16_to_cpu(u16));

                /* search for the HTS UUID in the advertising data */
                if (bt_uuid_cmp(uuid, BT_UUID_HTS) == 0)
                {
                    /* found the temperature server - stop scanning */
                    err = bt_le_scan_stop();
                    if (err)
                    {
                        PRINTF("Stop LE scan failed (err %d)\r\n", err);
                        break;
                    }
                    PRINTF("Found device: %s\r\n", addr);

                    for(uint32_t i=0; i<CONN_DEVICE; i++)
                    {

                    	if(default_conn[i] == NULL)
                    	{
							/* Send connection request */
							err = bt_conn_le_create(addr, BT_CONN_LE_CREATE_CONN,
													BT_LE_CONN_PARAM_DEFAULT,
													&default_conn[i]);
							break;
                    	}
                    }
                    if (err)
                    {
                        PRINTF("Create connection failed (err %d)\r\n", err);
                        scan_start();
                    }

                    continueParse = false;
                    break;
                }
            }
            break;
        }

        default:
        {
            break;
        }
    }

    return continueParse;
}

static void device_found(const bt_addr_le_t *addr, int8_t rssi, uint8_t type,
             struct net_buf_simple *ad)
{
    char dev[BT_ADDR_LE_STR_LEN];

	bt_addr_le_to_str(addr, dev, sizeof(dev));
	PRINTF("[DEVICE]: %s, AD evt type %u, AD data len %u, RSSI %i\r\n",
	       dev, type, ad->len, rssi);

	/* We're only interested in connectable events */
	if (type == BT_GAP_ADV_TYPE_ADV_IND ||
	    type == BT_GAP_ADV_TYPE_ADV_DIRECT_IND)
    {
		bt_data_parse(ad, device_scanned, (void *)addr);
	}
}

static int scan_start(void)
{
    struct bt_le_scan_param scan_param = {
            .type       = BT_LE_SCAN_TYPE_PASSIVE,
            .options    = BT_LE_SCAN_OPT_NONE,
            .interval   = BT_GAP_SCAN_FAST_INTERVAL,
            .window     = BT_GAP_SCAN_FAST_WINDOW,
    };

    return bt_le_scan_start(&scan_param, device_found);
}

static void disconnected(struct bt_conn *conn, uint8_t reason)
{
//    int32_t err;
//
//    PRINTF("Disconnected reason 0x%02x\n", reason);
//
//    if (default_conn != conn)
//    {
//        return;
//    }
//
//    bt_conn_unref(default_conn);
//    default_conn = NULL;
//
//    /* Restart scanning */
//    err = scan_start();
//    if (err)
//    {
//        PRINTF("Scanning failed to start (err %d)\n", err);
//    }
//    else
//    {
//        PRINTF("Scanning started\n");
//    }
}
#if CONFIG_BT_SMP
static void security_changed(struct bt_conn *conn, bt_security_t level, enum bt_security_err err)
{
    char addr[BT_ADDR_LE_STR_LEN];

    bt_addr_le_to_str(bt_conn_get_dst(conn), addr, sizeof(addr));

    PRINTF("Security changed: %s level %u (error %d)\r\n", addr, level, err);
}

static void auth_passkey_display(struct bt_conn *conn, unsigned int passkey)
{
    char addr[BT_ADDR_LE_STR_LEN];

    bt_addr_le_to_str(bt_conn_get_dst(conn), addr, sizeof(addr));

    PRINTF("Passkey for %s: %06u\r\n", addr, passkey);
}

static void auth_cancel(struct bt_conn *conn)
{
    char addr[BT_ADDR_LE_STR_LEN];

    bt_addr_le_to_str(bt_conn_get_dst(conn), addr, sizeof(addr));

    PRINTF("Pairing cancelled: %s\r\n", addr);
}
#endif
static struct bt_conn_cb conn_callbacks = {
    .connected = connected,
    .disconnected = disconnected,
#if CONFIG_BT_SMP
    .security_changed = security_changed,
#endif
};

#if CONFIG_BT_SMP
static struct bt_conn_auth_cb auth_cb_display = {
    .passkey_display = auth_passkey_display,
    .passkey_entry = NULL,
    .cancel = auth_cancel,
};
#endif

static void bt_ready(int err)
{
    if (err)
    {
        PRINTF("Bluetooth init failed (err %d)\r\n", err);
        return;
    }

    if (IS_ENABLED(CONFIG_BT_SETTINGS)) 
    {
        settings_load();
    }
    PRINTF("Bluetooth initialized\r\n");

    /* Register connection callback */
    bt_conn_cb_register(&conn_callbacks);
#if CONFIG_BT_SMP
    bt_conn_auth_cb_register(&auth_cb_display);
#endif

    /* Start scanning */
    err = scan_start();
    if (err)
    {
        PRINTF("Scanning failed to start (err %d)\r\n", err);
        return;
    }

    PRINTF("Scanning started\r\n");
}

void central_ht_task(void *pvParameters)
{
    int err;

    err = bt_enable(bt_ready);
    if (err)
    {
        PRINTF("Bluetooth init failed (err %d)\r\n", err);
        while (1)
        {
            vTaskDelay(2000);
        }
    }

    while (1)
    {
        vTaskDelay(1000);
    }
}

void central_ht_task_2(void *pvParameters)
{
    int err;


    while (1)
    {
        if(start_scanning == 1)
        {
            err = scan_start();
            if (err)
            {
                PRINTF("Scanning failed to start (err %d)\r\n", err);
                return;
            }

            PRINTF("Scanning started\r\n");
            start_scanning = 0;
        }
    	vTaskDelay(1000);
    }
}



