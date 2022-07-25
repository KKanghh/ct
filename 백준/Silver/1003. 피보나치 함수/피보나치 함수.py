import sys
input = sys.stdin.readline

fib = [[0] * 2 for _ in range(41)]
fib[0] = [1, 0]
fib[1] = [0, 1]

for i in range(2, 41):
    fib[i] = [fib[i - 1][0] + fib[i - 2][0], fib[i - 1][1] + fib[i - 2][1]]
    
    
size = int(input())
for _ in range(size):
    num = int(input())
    print(f'{fib[num][0]} {fib[num][1]}')