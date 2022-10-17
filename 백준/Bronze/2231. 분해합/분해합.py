num = input()
length = len(num)
num = int(num)

def jari(num):
    result = 0
    num = str(num)
    for i in num:
        result += int(i)
    return result

start = num - 9 * length

if start < 0:
    start = 1
    
while (start <= num):
    sum = 0
    sum += start + jari(start)
    if sum == num:
        break
    start += 1
        
if start == num + 1:
    print(0)
else:
    print(start)