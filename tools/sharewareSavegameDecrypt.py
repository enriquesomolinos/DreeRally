#!/usr/bin/python

import os
import struct
from collections import OrderedDict


FILE_NAME = "DR.SW6"  #change name to extract other file


def showData(f):
	f.seek(1)
	data = f.read(1)
	driverId = struct.unpack("<B",(data))[0] 
	print("DriverId: {0}".format(driverId))
	data = f.read(1)
	useWeapons = struct.unpack("<B",(data))[0] 
	print("useWeapons: {0}".format(useWeapons))
	data = f.read(1)
	
	difficulty = struct.unpack("<B",(data))[0] 
	print("Difficulty: {0}".format(difficulty))
	data = f.read(15)
	
	print("SaveGame Name: {0}".format(data))
	
	drivers=20
	for index in range(drivers):
		f.seek(19+108*index)
		name = f.read(12)
		print("#{0}".format(index))
		print(" Name: {0}".format(name))
		data = f.read(4)
		data = struct.unpack("I",(data))[0] 
		print(" Damage: {0}".format(data))
		data = f.read(4)
		data = struct.unpack("I",(data))[0] 
		print(" Engine: {0}".format(data%256))
		data = f.read(4)
		data = struct.unpack("I",(data))[0] 
		print(" Tire: {0}".format(data%255	))
		data = f.read(4)
		data = struct.unpack("I",(data))[0] 
		print(" Armour: {0}".format(data%255))
		data = f.read(4)
		data = struct.unpack("I",(data))[0] 
		print(" Car Type: {0}".format(data%255))
		
		if index ==driverId:
			data = f.read(4)
			data = struct.unpack("I",(data))[0] 
			print(" ?: {0}".format(data%255))
			data = f.read(4)
			data = struct.unpack("I",(data))[0] 
			print(" ?: {0}".format(data%255))
			data = f.read(4)
			data = struct.unpack("I",(data))[0] 
			print(" ?: {0}".format(data%255))
			data = f.read(4)
			data = struct.unpack("I",(data))[0] 
			print(" Color: {0}".format(data%255))
			data = f.read(4)
			data = struct.unpack("I",(data))[0] 
			print(" Money: {0}".format(data%(255*255)))
			data = f.read(4)
			data = struct.unpack("I",(data))[0] 
			print(" Loan Type: {0}".format(data%255))
			data = f.read(4)
			data = struct.unpack("I",(data))[0] 
			print(" Loan Races Left: {0}".format(data%255))
			data = f.read(4)
			data = struct.unpack("I",(data))[0] 
			print(" Actual car value: {0}".format(data%(255*255)))
			data = f.read(4)
			data = struct.unpack("I",(data))[0] 
			print(" Face: {0}".format(data%255))
			data = f.read(4)
			data = struct.unpack("I",(data))[0] 
			print(" Points: {0}".format(data))
			data = f.read(4)
			data = struct.unpack("I",(data))[0] 
			print(" Rank: {0}".format(data%255))
			data = f.read(4)
			data = struct.unpack("I",(data))[0] 
			print(" Races won: {0}".format(data))
			data = f.read(4)
			data = struct.unpack("I",(data))[0] 
			print(" Total races: {0}".format(data%255))
			data = f.read(4)
			data = struct.unpack("I",(data))[0] 
			print(" ?: {0}".format(data))
			data = f.read(4)
			data = struct.unpack("I",(data))[0] 
			print(" Total income: {0}".format(data))
			data = f.read(4)
			data = struct.unpack("I",(data))[0] 
			print(" Mines: {0}".format(data))
			data = f.read(4)
			data = struct.unpack("I",(data))[0] 
			print(" Spikes: {0}".format(data))
			data = f.read(4)
			data = struct.unpack("I",(data))[0] 
			print(" Rocket: {0}".format(data))
			data = f.read(4)
			data = struct.unpack("I",(data))[0] 
			print(" Sabotage: {0}".format(data))	
		else:
			f.read(19*4)

print("Reading: {0}".format(FILE_NAME))

f = open(FILE_NAME, "rb")
fDest = open(FILE_NAME + "_decrypted","w+")
try:
	positions = 2195
	initialPosition = 0
	for index in range(positions):
		
			
		f.seek(index)
		data = f.read(1)
		
		
		if index==0:
			initialPosition =struct.unpack("<B",(data))[0] 
			
			data =initialPosition
		else:
			tmpData = struct.unpack("<B",(data))[0] << index%5
			tmpData=tmpData %256
			data = tmpData|struct.unpack("<B",(data))[0] >> (8-index%5)
			data=data %256
			
			data +=-13* index
			data=data %256
			data=data+initialPosition
			data=data %256
		fDest.seek(index)	
		fDest.write(chr(data))
	
	showData(fDest)
	print("File readed: {0}".format(FILE_NAME))
	
finally:
	fDest.close()
	fDest.close()
	f.close()
	
	


