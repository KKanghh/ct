import sys

input = sys.stdin.readline

size = int(input())
array = list(map(int, input().split()))

print(f'{min(array)} {max(array)}')