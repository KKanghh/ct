repeat = int(input())

for i in range(repeat):
    x1, y1, r1, x2, y2, r2 = map(int, input().split())
    if (x1 == x2 and y1 == y2):
        if (r1 == r2):
            print(-1)
        else:
            print(0)
        continue
    l = ((x1 - x2) ** 2 + (y1 - y2) ** 2) ** (0.5)
    if l == r1 + r2:
        print(1)
    elif l > r1 + r2:
        print(0)
    elif l == abs(r1 - r2):
        print(1)
    elif l < abs(r1 - r2):
        print(0)
    else:
        print(2)