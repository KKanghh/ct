import sys

repeat = int(input())

for i in range(repeat):
    a, b = map(int, sys.stdin.readline().split())
    print(a + b)