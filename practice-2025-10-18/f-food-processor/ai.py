'''
    Link: https://open.kattis.com/contests/tnq2s6/problems/foodprocessor

    Constraints:
        t = target average piece size
        s = starting average piece size
        n = number of blades
        m = maximum average piece
        h = number of seconds to halve the avg piece size

        (1 <= t < s <= 10^6)
        (1 <= n <= 10^6)
        (1 <= m, h <= 10^6)
'''

import math

s, t, n = map(int, input().split())
blades = []
for _ in range(n):
    m, h = map(int, input().split())
    blades.append((m, h))

# Sort blades by maximum size descending
blades.sort(reverse=True)

# Check if we can start
if not blades or blades[0][0] < s:
    print(-1)
    exit()

# Build a list of (size, fastest_h) for each important size range
# We only switch when we find a faster blade
segments = []
current_fastest = float('inf')

for m, h in blades:
    if m < t:  # Skip blades that can't reach our target
        continue
    if h < current_fastest:
        # Found a faster blade, create a segment
        segments.append((m, h))
        current_fastest = h

# Add the starting point if needed
if not segments or segments[0][0] < s:
    # Find fastest blade that can handle s
    fastest_at_s = min((h for m, h in blades if m >= s), default=float('inf'))
    if fastest_at_s == float('inf'):
        print(-1)
        exit()
    segments.insert(0, (s, fastest_at_s))

# Calculate total time
total_time = 0
current_size = s

for i in range(len(segments)):
    blade_m, blade_h = segments[i]
    
    # Determine the target size for this segment
    if i + 1 < len(segments):
        # Go down to where the next faster blade becomes available
        target_size = segments[i + 1][0]
    else:
        # Last segment - go to target
        target_size = t
    
    if current_size <= target_size:
        continue
    
    # Use current blade from current_size to target_size
    time_needed = blade_h * math.log2(current_size / target_size)
    total_time += time_needed
    current_size = target_size

print(total_time)
