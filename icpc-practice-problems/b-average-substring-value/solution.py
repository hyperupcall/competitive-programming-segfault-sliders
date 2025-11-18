import math

s = input()
n = len(s)

left = [0] * n
right = [0] * n
stack = []

for i in range(n):
    while stack and s[stack[-1]] < s[i]:
        stack.pop()
    left[i] = stack[-1] if stack else -1
    stack.append(i)

stack.clear()

for i in range(n - 1, -1, -1):
    while stack and s[stack[-1]] <= s[i]:
        stack.pop()
    right[i] = stack[-1] if stack else n
    stack.append(i)

total_sum = 0

for i in range(n):
    digit = ord(s[i]) - ord('0')
    count = (i - left[i]) * (right[i] - i)
    total_sum += (digit * count)

total_count = (n * (n + 1)) // 2

reducer = math.gcd(total_sum, total_count)
total_sum //= reducer
total_count //= reducer

if total_count == 1:
    print(total_sum)
elif total_sum > total_count:
    print(f'{total_sum // total_count} {total_sum % total_count}/{total_count}')
else:
    print(f'{total_sum}/{total_count}')