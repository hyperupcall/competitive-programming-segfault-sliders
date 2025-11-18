n = int(input())

for _ in range(n):
    full_str = input()
    abbrev = input()
    
    chars_in_full_str = set(full_str)
    
    intuitive = True
    for c in abbrev:
        if c not in chars_in_full_str:
            intuitive = False
            break
    
    if intuitive:
        print('YES')
    else:
        print('NO')

