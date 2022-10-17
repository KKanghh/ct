xs = list()
ys = list()

for i in range(3):
    temp_x, temp_y = map(int, input().split())
    xs.append(temp_x)
    ys.append(temp_y)
    
for x in xs:
    if xs.count(x) == 1:
        print(x, end = " ")

for y in ys:
    if ys.count(y) == 1:
        print(y)