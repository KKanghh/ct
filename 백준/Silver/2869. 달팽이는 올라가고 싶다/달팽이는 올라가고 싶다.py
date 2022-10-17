import math

up, down, goal = map(int, input().split())

print(math.ceil((goal - up) / (up - down) + 1))