#!/usr/bin/python

import os
import struct
from collections import OrderedDict


FILE_NAME = "MUSICS.BPA"  #change name to extract other file
FILE_NAME_SIZE = 13
FILE_SIZE = 4

FAT_SIZE = 255 *17
INITIAL_OFFSET = FAT_SIZE  + 4


def getNumberOfFiles(f):
    f.seek(0)
    num_files = struct.unpack("<i", f.read(3) + '\x00')
    return num_files


def getFAT(f,num_files):
    fat = OrderedDict()
    f.seek(4)
    for x in range(num_files):
        file_name = ''
        for i in range(FILE_NAME_SIZE):
            file_name_byte =f.read(1)
            if struct.unpack("<B",(file_name_byte))[0]==0:
                file_name = file_name + file_name_byte
            else:
                file_name_byte = struct.unpack("<B",(file_name_byte))[0] -(117 -(i*3))
                file_name = file_name + chr(file_name_byte)
        file_size = struct.unpack("<i",f.read(FILE_SIZE))[0]
        fat[file_name.rstrip('\0')] = file_size
    
    return fat

def extractFile(f,file_name,size,start_offset):
    os.mkdir(FILE_NAME, 0755)
    return "a"

print("Reading: {0}".format(FILE_NAME))

f = open(FILE_NAME, "rb")
try:
    num_files =getNumberOfFiles(f)[0]
    print("Number of files: {0} ".format(num_files))
    fat = getFAT(f,num_files)

    offset = INITIAL_OFFSET
    
    os.mkdir(FILE_NAME + "_dir" , 0755)
	
    for name,size in fat.items():
               
        fDest = open(FILE_NAME + "_dir/" +name, "wb")        
        for index in range(size):
            f.seek(index+offset)
            file_data = f.read(1)
            fDest.seek(index)
            fDest.write(file_data)
        fDest.close()
        print(name)
        offset =offset + size

finally:
    f.close()


