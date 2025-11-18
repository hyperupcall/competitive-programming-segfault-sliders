g, r = map(int, input().split())

if g == 0:
    print(0)
    exit(0)

if g < r:
    print(g * 10)
    exit(0)
    
num_tens = 0
num_threes = 0
num_ones = 0

if r:
    g -= r
    num_tens += r

if g // 3:
    num_tens += (g // 3)
    g = g - 3 * (g // 3)
if g // 2:
    num_threes += (g // 2)
    g = g - 2 * (g // 2)
if g:
    num_ones = 1

print(10 * num_tens + 3 * num_threes + num_ones)