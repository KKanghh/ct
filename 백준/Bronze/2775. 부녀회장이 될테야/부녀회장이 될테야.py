apartment = [[0 for col in range(15)] for row in range(15)]
for i in range(15):
    for j in range(15):
        if i == 0:
            apartment[i][j] = j
        elif j == 0:
            apartment[i][j] = 0
        else:
            apartment[i][j] = apartment[i-1][j] + apartment[i][j-1]
            
            
times = int(input())

for time in range(times):
    k = int(input())
    n = int(input())
    
    print(apartment[k][n])