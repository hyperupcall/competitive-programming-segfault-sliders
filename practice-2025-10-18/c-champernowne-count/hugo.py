'''
    Link: https://open.kattis.com/problems/champernownecount

    Constraints:

        (1 <= n <= 10^5)
        (1 <= k <= 10^9)
'''

n, k = map(int, input().split())

count = 0
word_mod = 0

for i in range(1, n + 1):
    digits = len(str(i))

    word_mod = (word_mod * pow(10, digits, k) + i) % k

    if word_mod == 0:
        count += 1

print(count)