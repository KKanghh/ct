import sys
input = sys.stdin.readline
size = int(input())
nums1 = list(map(int, input().split()))
nums = set(nums1)
nums = sorted(list(nums))
rank = {nums[i]:i for i in range(len(nums))}
for num in nums1:
    print(rank[num], end = " ")