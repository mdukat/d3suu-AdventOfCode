#!/usr/bin/python3 

f = open("./input.txt", 'r')

checksum = 0

while(True):
	line = f.readline()
	if(line == ""):
		break

	line_a = list(line[:-1]) # get rid of \n character

	print(list(line))
	for a in line_a:
		line.count(a)
