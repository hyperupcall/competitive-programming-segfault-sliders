s = input().strip(' ').upper()
size = 0

freq = [0] * 26
for c in s:
    index = (ord(c) - ord('A'))
    if 0 <= index < 26:
        size += 1
        freq[index] += 1
        
freq.sort(reverse=True)

#print(freq)
#print(size)

final_cost = 0
temp_cost = -1
i = 0

costs = [
    1,
    3,
    3,
    5, # 4
    5,
    5,
    7,
    7, # 8
    7,
    7,
    7,
    9, # 12
    9,
    9,
    9,
    9, # 16
    9,
    9,
    9,
    11, # 20
    11,
    11,
    11,
    11, # 24
    11,
    11
]

for i in range(len(freq)):
    final_cost += freq[i] * costs[i]

#while i < 26 and freq[25 - i] != 0:
#    if i % 3 == 0:
#        temp_cost += 2
#    final_cost += (freq[25 - i] * temp_cost)
#    i += 1

final_cost += ((size - 1) * 3)

print(final_cost)
