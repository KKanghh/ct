import sys
input = sys.stdin.readline
size = int(input())
dots = [[0] * 2 for _ in range(size)]

for i in range(size):
    dots[i][0], dots[i][1] = map(int, input().split())

dots = sorted(dots)

for dot in dots:
    print(f'{dot[0]} {dot[1]}')