'''
    Link: https://open.kattis.com/problems/twochartsbecomeone

    Constraints:

        1 to 1,000,000 nodes
        0 to 100 children nodes for each node

'''

def parse_and_normalize(tree, idx=0):
    # Returns (value, [sorted_children], next_idx)
    if idx >= len(tree) or tree[idx] == ')':
        return None, idx
    
    # Read string value as int w/ num = num * 10 to shift left,
    # then add digit val 0-9 to shifted num
    val = 0
    while idx < len(tree) and tree[idx].isdigit():
        val = val * 10 + int(tree[idx])
        idx += 1
    
    children = []
    while idx < len(tree) and tree[idx] == '(':
        idx += 1
        child, idx = parse_and_normalize(tree, idx) # recursively add nested lists for each trees child
        if child:
            children.append(child)
        if idx < len(tree) and tree[idx] == ')':
            idx += 1
    
    children.sort() # sort the final result so we return fully sorted lists to compare
    return (val, tuple(children)), idx

tree1 = input().replace(' ', '')
tree2 = input().replace(' ', '')

t1_struct, _ = parse_and_normalize(tree1)
t2_struct, _ = parse_and_normalize(tree2)

print("Yes" if t1_struct == t2_struct else "No")