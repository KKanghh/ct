nums = [0 for i in range(9)]
max = 0
index = -1
for a in range(9):
    nums[a] = int(input())
    if nums[a] > max:
        max = nums[a]
        index = a
        
print(f'{max}\n{index+1}')