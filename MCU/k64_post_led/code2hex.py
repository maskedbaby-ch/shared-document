def readFile():
	with open('book.txt', 'r', encoding='UTF-8') as f:        
		data = f.read()
	f.close()
	return data
	
def writeFile(str):
	with open('array.txt', 'w', encoding='UTF-8') as f:        
		data = f.write(str)
	f.close()

htmlData = readFile()

htmlStr = '';
sum = len(htmlData) #计算总长
arrayStr = ''

for i in range(sum):
	temp = str(hex(ord(htmlData[i]))) #ascii转16再转字符串
	if len(temp) == 3:   #0xa转0x0a
		tList = list(temp)
		tList.insert(2,'0')
		temp = "".join(tList) #发现0x0a前面没有0x0d，添加
		if temp == "0x0a":
			temp = "0x0d0x0a"
	htmlStr += temp

cc = 0
leng = len(htmlStr)
print(leng)
while cc < leng :
	if cc % 40 == 0 and cc >= 36: #4个字节一个16进制，一个16进制字节加一个逗号和空格
		arrayStr += '\r\t'  #每十个16进制，换行
	if cc != leng - 4:
		tempStr = htmlStr[cc:cc+4]
		tempStr = tempStr + ',' + ' '
		arrayStr += tempStr

	else:
		tempStr = htmlStr[cc:cc+4]  #最后一个16进制字节不加东西
		arrayStr += tempStr
	cc += 4

writeFile('{'+ '\r\n\t' + arrayStr +'}')