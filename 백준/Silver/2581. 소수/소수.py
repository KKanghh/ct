import math

small = int(input())
big = int(input())
num_list = list(range(small, big + 1))

for num in range(small, big + 1):
    if num == 1:
        num_list.remove(1)
        continue
    for i in range(2, math.floor(math.sqrt(num) + 1)):
        if num % i == 0:
            num_list.remove(num)
            break
if len(num_list) == 0:
    print(-1)
else:
    print(sum(num_list))
    print(num_list[0])