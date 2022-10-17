import math
iter = int(input())

for i in range(iter):
    h, w, n = map(int, input().split())
    floor = n % h
    if floor == 0:
        floor = h
    print(f'{floor}{math.ceil(n / h):02}')