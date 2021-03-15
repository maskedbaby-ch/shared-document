from __future__ import division, print_function, absolute_import
import numpy as np
from PIL import Image
import sys
import serial


img = Image.open(sys.argv[1]).convert('L')

if img.size[0] != 28 or img.size[1] != 28:
    img = img.resize((28, 28))


arr = []

for i in range(28):
    for j in range(28):

        pixel = int((1.0 - float(img.getpixel((j, i)))/255.0)*127)

        arr.append(pixel)
arr1 = np.array(arr).reshape((1, 28, 28, 1))
f = open('content.txt', 'w')
#f.write('#define IMG%d {'% (1))

np.round(arr1.flatten()).tofile(f, sep=" ", format="%02x")
#f.write('} \n')
f.close()
#print(arr)
#print(arr1)

