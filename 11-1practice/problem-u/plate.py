#!/usr/bin/env python3
n, m = list(map(int, input().split()))
bad_words = []
mp = {
	'0': 'O',
	'1': 'L',
	'2': 'Z',
	'3': 'E',
	'5': 'S',
	'6': 'B',
	'7': 'T',
	'8': 'B'
}

for _ in range(n):
	word = input()
	bad_words.append(word)

for _ in range(m):
	s = ''
	for ch in input():
		if ch in mp:
			s += mp[ch]
		else:
			s += ch

	is_valid = True	
	for bad_word in bad_words:
		if bad_word in s:
			is_valid = False
			break
	
	if is_valid:
		print('VALID')
	else:
		print('INVALID')
