import math

s, t, n = map(int, input().split(" "))

if t > s:
    print(-1)
    exit(0)

if t == s:
    print(0)
    exit(0)

l = []
for _ in range(n):
    m, h = map(int, input().split(" "))
    l.append((m, h))
l.append((t, "target"))
l.sort(reverse=True)

if s > l[0][0]:
    print(-1)
    exit(0)

time = 0
fastest_blade = l[0]
current_piece_size = s
i = 0
# print(l)
for m, h in l:
    if h == "target":
        break

    if current_piece_size <= m and h < fastest_blade[1]:
        fastest_blade = (m, h)

    m, h = fastest_blade
    Sf = l[i + 1][0]
    time += h * math.log2(Sf / current_piece_size) / math.log2(1 / 2)
    # time += h * math.log((Sf / current_piece_size) - 0.5)
    current_piece_size = Sf
    fastest_blade = m, h
    i += 1

print(time)
