nums = set(range(1, 10001))

for i in range(1,10001):
    num = i
    while num > 0:
        i += num % 10
        num //= 10
    if i in nums:
        nums.remove(i)
    
for num in list(nums):
    print(num)