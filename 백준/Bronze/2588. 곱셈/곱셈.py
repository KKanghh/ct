a = int(input())
b = int(input())
m = a * b
while (b != 0):
    c = b % 10
    b = b // 10
    print(a * c)

print(m)