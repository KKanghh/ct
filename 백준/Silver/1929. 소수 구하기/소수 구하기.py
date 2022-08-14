import math

lower_limit, upper_limit = map(int,input().split())
num_list = list(range(upper_limit + 1))
num_list[1] = 0

for i in range(2, upper_limit + 1):
    if list[i] != 0:
        for j in range(2 * i, upper_limit + 1, i):
            num_list[j] = 0

while lower_limit <= upper_limit:
    if num_list[lower_limit] != 0:
        print(lower_limit)
    lower_limit += 1