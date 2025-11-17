n, a, b = map(int, input().split())

ranges = [ tuple(map(int, input().split())) for _ in range(n) ]

probability = 1

for s, e in ranges:
    if e <= a or s >= b:
        print(1)
        exit(0)
    
    if a <= s and e <= b:
        continue

    if s <= a and b <= e:
        continue

    start_overlap = max(a, s)
    end_overlap = min(b, e)

    probability *= ((end_overlap - start_overlap) / (b - a))

print(1 - probability)
