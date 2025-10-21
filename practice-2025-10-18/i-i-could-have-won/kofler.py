s = input()

record = []
should_break = False
for k in range(1, len(s) + 1):
    a_wins = 0
    b_wins = 0

    i = 0
    a = 0
    b = 0
    while a < k and b < k and i < len(s):
        if s[i] == 'A':
            a += 1
        else:
            b += 1

        if max(a, b) == k:
            if a > b:
                a_wins += 1
            elif b > a:
                b_wins += 1
            expr = 'A' if a > b else 'B'
            # print(f'k: {k}  i: {i+1}  {expr}')
            a = 0
            b = 0

        i += 1

    if a_wins > b_wins:
        record.append(k)

    if should_break:
        break

print(len(record))
for i, k in enumerate(record):
    if i < len(record) - 1:
        print(k, end=' ')
    else:
        print(k)
