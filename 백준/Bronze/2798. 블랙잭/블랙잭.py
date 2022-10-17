count, stand = map(int, input().split())
card_list = list(map(int, input().split()))
max = 0

for i in range(count):
    for j in range(i+1, count):
        for k in range(j+1, count):
            sum = card_list[i] + card_list[j] + card_list[k]
            if sum <= stand and sum > max:
                max = sum
                
                
print(max)