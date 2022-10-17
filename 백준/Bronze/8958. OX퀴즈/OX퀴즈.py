repeat = int(input())

scores = [0] * repeat

for i in range(repeat):
    answer = input()
    score = 0
    for word in answer:
        if word == 'O':
            score += 1
        else:
            score = 0
        scores[i] += score
        
for i in scores:
    print(i)