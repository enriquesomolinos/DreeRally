#!/usr/bin/python

import os
import struct
from collections import OrderedDict


FILE_NAME = "DR.SW6_decrypted"  #change name to extract other file
FILE_NAME_DEST = "DR.SW6_crypted"  #change name to extract other file



print("Reading: {0}".format(FILE_NAME))

f = open(FILE_NAME, "rb")
fDest = open(FILE_NAME_DEST,"w+")
try:
	positions = 2179
	initialPosition = 0
	for index in range(positions):
		
			
		f.seek(index)
		data = f.read(1)
		
		
		if index==0:
			initialPosition =struct.unpack("<B",(data))[0] 
			
			data =initialPosition
		else:
			data = struct.unpack("<B",(data))[0] 
			data=data-initialPosition
			data=data %256
			data +=17* index
			data=data %256
			tmpData = data >> index%6
			data=data %256
			data = tmpData|data << (8-index%6)			
			data=data %256
			
			
		fDest.seek(index)
		fDest.write(chr(data))
	
	
	print("File readed: {0}".format(FILE_NAME))
	
finally:
	fDest.close()
	fDest.close()
	f.close()
	
	


