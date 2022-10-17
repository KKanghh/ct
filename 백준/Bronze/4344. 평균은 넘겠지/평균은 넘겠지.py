time = int(input())

for i in range(time):
    scores = list(map(int, input().split()))
    size = scores[0]
    scores = scores[1:]
    avg = sum(scores) / size
    count = 0
    for score in scores:
        if score > avg:
            count += 1
    print("%.3f%%" %((count / size) * 100))