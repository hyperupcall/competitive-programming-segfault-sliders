n = int(input())

vals = {'A' : 4, 'B' : 3, 'C' : 2, 'D' : 1, 'E' : 0}

unweighted = 0
additive = 0

for _ in range(n):
    grade = input()

    letter = grade[0]
    tier = int(grade[1])

    unweighted += vals[letter]

    if letter not in { 'D', 'E' }:
        if tier == 1:
            additive += 0.05
        elif tier == 2:
            additive += 0.025
    
print(unweighted / n + additive)