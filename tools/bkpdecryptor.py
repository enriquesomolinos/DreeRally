#!/usr/bin/python

import os
import struct
from collections import OrderedDict
from binascii import hexlify

GIF_HEADER_SIZE =13
PALETTE_SIZE =768
BPK_FILE_NAME = "FACE01.BPK"  

BPK_W = 64
BPK_H = 64
PAL_FILE_NAME = "MENU.PAL"  




def byte(number, i):
    return (number & (0xff << (i * 8))) >> (i * 8)




print("CREATING: {0}".format(BPK_FILE_NAME+".gif"))


f = open(BPK_FILE_NAME+".gif", "wb")


try:
	f.write("GIF89a")
	f.write(chr(BPK_W))
	f.write(chr(0))
	f.write(chr(BPK_H))
	f.write(chr(0))
	
	"""
    <Packed Fields>  =      Global Color Table Flag       1 Bit   1
                            Color Resolution              3 Bits  111
                            Sort Flag                     1 Bit   0
                            Size of Global Color Table    3 Bits  111
    """
	f.write(chr(int("F7", 16)))   
	
	""" background color index"""
	f.write(chr(0))
	
	""" pixel aspect ratio"""
	f.write(chr(0))
	
	
	fpalette = open(PAL_FILE_NAME, "rb")
	
	""" modify the palette
	data = fpalette.read(paletteSize)
	f.write(data)
	"""
	for x in range(0,PALETTE_SIZE,3):
		fpalette.seek(x)
		data = fpalette.read(3)
		data = hexlify(data)
		data=int(data,16)
		
		f.seek(GIF_HEADER_SIZE+x)
		f.write(chr(byte(data,0)))
		f.write(chr(byte(data,1)))
		f.write(chr(byte(data,2)))
	
	
	
	fbpk = open(BPK_FILE_NAME, "rb")
	
	fbpk.seek(0, os.SEEK_END)
	size = fbpk.tell()
	fbpk.seek(0)
	
	
	"""  bloque a fuego    """
	f.write(chr(int("21", 16)))   
	f.write(chr(int("f9", 16)))   
	f.write(chr(int("04", 16)))   
	f.write(chr(int("01", 16)))   
	f.write(chr(int("00", 16)))   
	f.write(chr(int("00", 16)))   
	f.write(chr(int("fc", 16)))   
	f.write(chr(int("00", 16)))   
	
	""" image descriptor     """
	f.write(chr(int("2c", 16)))   
	f.write(chr(int("00", 16)))   
	f.write(chr(int("00", 16)))   
	f.write(chr(int("00", 16)))   
	f.write(chr(int("00", 16)))   
	f.write(chr(64))   
	f.write(chr(int("00", 16)))   
	f.write(chr(64))   
	f.write(chr(int("00", 16)))   
	f.write(chr(int("00", 16)))
	
	   
	f.write(chr(int("08", 16)))   
	f.write(chr(int("ff", 16))) 
	bpkpos=0
	while 1:
		 
		bpkData = fbpk.read(255)
		f.write(bpkData)
		bpkpos=bpkpos+255
		if bpkpos>=size:
			break
		f.write(chr(int("ff", 16))) 
		
	
	if size+255-bpkpos>0:
		
		f.write(chr(size+255-bpkpos)) 
		bpkData = fbpk.read(size+255-bpkpos)
		f.write(bpkData)
	
	
	

	f.write(chr(int("00", 16)))   
	f.write(chr(int("3b", 16)))   
finally:
    f.close()