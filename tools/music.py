#!/usr/bin/python

import os
import struct
from collections import OrderedDict
import binascii


FILE_NAME = "TR9-MUS.CMF"  #change name to extract other file
FILE_NAME_DEST = "TR9-MUS.CMF.s3m"  #change name to extract other file


print("Reading: {0}".format(FILE_NAME))

f = open(FILE_NAME, "rb")
fDest = open(FILE_NAME_DEST , "wb")
try:
	fileSize = os.path.getsize(FILE_NAME)
	print("File size: ")
	print(fileSize)
	for x in range(fileSize):
		f.seek(x)
		
		file_byte=f.read(1)
		file_byte =ord(file_byte)
		
		result = file_byte%256 << (x%7);
		
		file_byte = result | (file_byte%256 >> (8 - x%7));
		
		file_byte=file_byte %256;
		
		file_byte = -109 - (17 * x) + (file_byte%256);	
		
		fDest.seek(x)
		fDest.write(chr(file_byte %256))
		

finally:
    f.close()

	

