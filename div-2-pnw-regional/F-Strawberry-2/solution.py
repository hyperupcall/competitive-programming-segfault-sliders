from collections import Counter

s = input()
repeats = int(input())

freqs = Counter(s)

rs = 0

cycles = repeats // 26
excess = repeats % 26

if cycles:
    for c in range(ord('a'), ord('z') + 1):
        rs += (freqs[chr(c)] * cycles)

for i in range(ord('r'), ord('r') + excess):
    rs += freqs[chr(((i - ord('a')) % 26) + ord('a'))]

print(rs)