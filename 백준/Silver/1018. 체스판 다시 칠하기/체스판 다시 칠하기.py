length, width = map(int, input().split())
words = list()
board = [[0] * 8 for _ in range(8)]

for i in range(length):
    words.append(input())

least = 64

for i in range(length - 7):
    for j in range(width - 7):
        temp = [row[j:j+8] for row in words[i:i+8]]#words[i:i+7][j:j+7]
        flag = temp[0][0]
        for k in range(8):
            for l in range(8):
                if (k + l) % 2 == 0:
                    if temp[k][l] == flag:
                        board[k][l] = 0
                    else:
                        board[k][l] = 1
                else:
                    if temp[k][l] == flag:
                        board[k][l] = 1
                    else:
                        board[k][l] = 0
        paint = 0
        for k in board:
            paint += sum(k)

        if paint > 32:
            paint = 64 - paint
        
        if paint < least:
            least = paint
            
            
print(least)