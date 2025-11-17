def can_solve_with_sum(problems, total):
    impl_values = {p[0] for p in problems}

    impl_values.add(0)
    impl_values.add(total)
    
    for start_i in sorted(impl_values):
        if start_i > total: continue
        
        start_t = total - start_i
    
        if simulate_all_paths(problems, start_i, start_t):
            return True
    
    return False

def simulate_all_paths(problems, impl_skill, think_skill):
    states = {(impl_skill, think_skill)}
    
    for i, t in problems:
        next_states = set()
        
        for curr_i, curr_t in states:
            if curr_i >= i and curr_t >= t:
                next_states.add((curr_i + 1, curr_t))
                next_states.add((curr_i, curr_t + 1))
        
        states = next_states
        
        if not states:
            return False
        
    return True

n = int(input())
problems = [ tuple(map(int, input().split())) for _ in range(n) ]

low = problems[0][0] + problems[0][1]
high = 10 ** 9 + 1

while low < high:
    mid = low + (high - low) // 2
    if can_solve_with_sum(problems, mid):
        high = mid
    else:
        low = mid + 1

print(low)