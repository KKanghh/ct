import math

count = int(input())

for i in range(count):
    now, goal = map(int, input().split())
    dist = goal - now
    
    n = math.ceil(math.sqrt(dist)) - 1
    
    if dist <= n * n + n:
        print(2 * n)
    else:
        print(2 * n + 1)