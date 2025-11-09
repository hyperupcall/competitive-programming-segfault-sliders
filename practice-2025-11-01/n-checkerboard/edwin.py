#!/usr/bin/env python3
r, c, a, b = list(map(int, input().split()))

grid2 = []

colnums = []
for _ in range(a):
	colnums.append(int(input()))

rownums = []
for _ in range(b):
	rownums.append(int(input()))

color = 'B'
for colnum in colnums:
	for _ in range(colnum):
		line = ''
		for rownum in rownums:
			#print('colnum', color, rownum)
			line += color * rownum
			if color == 'B':
				color = 'W'
			else:
				color = 'B'
		if b % 2 != 0:
			if color == 'B':
				color = 'W'
			else:
				color = 'B'
		grid2.append(line)
		line = ''
	if b % 2 == 0 or True:
		if color == 'B':
			color = 'W'
		else:
			color = 'B'
			

for line in grid2:
	print(line)
