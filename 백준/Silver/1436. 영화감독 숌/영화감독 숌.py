num = int(input())

flag = '666'
count = 0
digit = 666

while count < num:
    step_str = str(digit)
    if flag in step_str:
        count += 1
    digit += 1
    
print(digit - 1)