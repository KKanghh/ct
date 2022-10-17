size = int(input())

nums = [0] * size

for i in range(size):
    nums[i] = int(input())
    
nums.sort()

for x in nums:
    print(x)