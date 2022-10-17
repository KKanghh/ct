import sys
input = sys.stdin.readline

size = int(input())
result = [[0] * (size + 1) for _ in range(size + 1)]
nums = list(map(int, input().split()))

for i in range(size):
    for j in range(1, size + 1):
        if i + j > size:
            break
        if i == 0:
            result[j][j + i] = 1
        elif i == 1 and nums[j - 1] == nums[j + i - 1]:
            result[j][j + i] = 1
        elif result[j + 1][j + i - 1] == 1 and nums[j - 1] == nums[j + i - 1]:
            result[j][j + i] = 1

for i in range(int(input())):
    a, b = map(int, input().split())
    if result[a][b] == 1:
        print(1)
    else:
        print(0)