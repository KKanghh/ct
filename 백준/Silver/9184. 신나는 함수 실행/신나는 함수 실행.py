array = [[[0 for _ in range(21)] for _ in range(21)] for _ in range(21)]

for a in range(21):
    for b in range(21):
        for c in range(21):
            if a == 0 or b == 0 or c == 0:
                array[a][b][c] = 1
            elif a < b and b < c:
                array[a][b][c] = array[a][b][c - 1] + array[a][b - 1][c - 1] - array[a][b - 1][c]
            else:
                array[a][b][c] = array[a - 1][b][c] + array[a - 1][b - 1][c] + array[a - 1][b][c - 1] - array[a - 1][b - 1][c - 1]

a, b, c = map(int, input().split())
while(a != -1 or b != -1 or c != -1):
    if a <= 0 or b <= 0 or c <= 0:
        print(f'w({a}, {b}, {c}) = {array[0][0][0]}')
    elif a > 20 or b > 20 or c > 20:
        print(f'w({a}, {b}, {c}) = {array[20][20][20]}')
    else:
        print(f'w({a}, {b}, {c}) = {array[a][b][c]}')
    a, b, c = map(int, input().split())
          
