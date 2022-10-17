array = [0] * 42

for i in range(10):
    num = int(input())
    array[num % 42] += 1
        
count = 0
for e in array:
    if e > 0:
        count += 1
        
print(count)