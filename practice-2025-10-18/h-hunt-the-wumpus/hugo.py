'''
    Link: https://open.kattis.com/problems/huntthewumpus

    Constraints:

        Guarantee that the user will eventually hit all 4
        10 x 10 grid 0 indexed (0 - 9, 0 - 9)
'''
import math
import sys

def generate_random_number(seed : int):
    return (seed + math.floor(seed / 13) + 15)


seed = int(input())

wumpus_coords = set()

while len(wumpus_coords) < 4:
    seed = generate_random_number(seed)
    coord = (x := seed % 100 // 10, y := seed % 10)
    wumpus_coords.add(coord)

score = 0

while wumpus_coords:
    guess = int(input())
    guess = (x := guess % 100 // 10, y := guess % 10)

    if guess in wumpus_coords:
        print('You hit a wumpus!')
        wumpus_coords.remove(guess)
    
    min_dist = sys.maxsize

    for x, y in wumpus_coords:
        min_dist = min(min_dist, (abs(x - guess[0]) + abs(y - guess[1])))
    
    if wumpus_coords:
        print(min_dist)

    score += 1

print(f'Your score is {score} moves.')
