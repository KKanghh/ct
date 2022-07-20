import sys
input = sys.stdin.readline
nums_count = dict()

size = int(input())

for i in range(size):
    num = int(input())
    if num in nums_count:
        nums_count[num] += 1
    else:
        nums_count[num] = 1
        
nums_count = sorted(nums_count.items())
    
for key,value in nums_count:
    temp = value
    while temp > 0:
        print(key)
        temp -= 1