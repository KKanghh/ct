origin = int(input())
num = origin
cycle = 0

while True:
    ten = num // 10
    one = num % 10
    num = (ten + one) % 10 + one * 10
    cycle += 1
    if num == origin:
        break
        
print(cycle)