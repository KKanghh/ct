repeat = int(input())

for i in range(repeat):
    a, b = map(int, input().split())
    print(f"Case #{i + 1}: {a + b}")