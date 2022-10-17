num = int(input())

persons = [[0, 0] for _ in range(num)]
result = [0] * num

for x in persons:
    x[0], x[1] = map(int, input().split())

for i in persons:
    rank = 1
    for j in persons:
        if i[0] < j[0] and i[1] < j[1]:
            rank += 1
    print(rank)
