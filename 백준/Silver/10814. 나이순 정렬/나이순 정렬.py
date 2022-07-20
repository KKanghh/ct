import sys
input = sys.stdin.readline
size = int(input())

person = list()

for i in range(size):
    a, b = input().split(" ")
    person.append([int(a), b.rstrip(), i])
    
person = sorted(person, key = lambda x : (x[0], x[2]))

for i in person:
    print(f'{i[0]} {i[1]}')