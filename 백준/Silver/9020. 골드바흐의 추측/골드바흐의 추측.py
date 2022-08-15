num_list = [0] * 30000
num_list[1] = 1

for i in range(2, 30000):
    if num_list[i] == 0:
        for j in range(2 * i, 30000, i):
            num_list[j] = 1

            
repeat = int(input())

for k in range(repeat):
    find = False
    num = int(input())
    partition = num // 2
    while find == False:
        if num_list[partition] == 0 and num_list[num - partition] == 0:
            find = True
            print(f'{partition} {num - partition}')
        partition -= 1