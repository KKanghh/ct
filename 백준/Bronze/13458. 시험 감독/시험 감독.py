import math

classroom = int(input())
student = list(map(int, input().split()))
main_director, sub_director = map(int, input().split())
nr_director = 0

for i in range(classroom):
    if main_director > student[i]:
        nr_director += 1
        continue
    
    nr_director += math.ceil((student[i] - main_director) / sub_director) + 1

print(nr_director)