import math

def get_costs_by_length():
    all_patterns = []

    for length in range(1, 10):
        for num_dots in range(length + 1):
            num_dashes = length - num_dots
            cost = num_dots * 1 + num_dashes * 3 + (length - 1) * 1
            count = math.comb(length, num_dots) # Search up Pascal's triangle Combinations for explanation 

            all_patterns.extend([cost] * count)

    all_patterns.sort()
    return all_patterns[:26]

s = input().strip(' ').lower()
char_count = 0

freqs = [0] * 26
for c in s:
    if c.isalpha():
        freqs[ord(c) - ord('a')] += 1
        char_count += 1
        
total_cost = 0
freqs.sort(reverse=True)
costs = get_costs_by_length()

i = 0
while i < 26 and freqs[i] > 0:
    total_cost += (freqs[i] * costs[i])
    i += 1

total_cost += ((char_count - 1) * 3)

print(total_cost)