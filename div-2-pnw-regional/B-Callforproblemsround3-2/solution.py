n, t = map(int, input().split())

nums = list(map(int, input().split()))

nums.sort()

no_conflicts = False

while nums and not no_conflicts:
    no_conflicts = True

    l = 0
    r = 1
    while r < len(nums):
        while r < len(nums) and nums[r] - nums[l] < t:
            nums.pop(r)
            no_conflicts = False
        l += 1
        r += 1

print(len(nums))
