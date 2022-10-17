num = int(input())

house = 1
count = 1

while house < num:
    house += 6 * count
    count += 1
    
print(count)