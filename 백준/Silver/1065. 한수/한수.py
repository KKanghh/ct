def han(num):
    if num < 100:
        return num

    count = 99
    for i in range(101, num + 1):
        one = i % 10
        i //= 10
        ten = i % 10
        i //= 10
        hund = i
    
        if 2 * ten == hund + one:
            count += 1
        
    return count

num = int(input())
print(han(num))