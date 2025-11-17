n = int(input())
s = input()

valid_options = 0
current_range = 0

for i in range(n):
    if s[i] == '2':
        valid_options += (current_range // 2)
        current_range = 0
    elif s[i] == '1':
        current_range += 1
    else:
        current_range += 2

if current_range:
    valid_options += (current_range // 2)

print(valid_options)