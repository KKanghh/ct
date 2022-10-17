word = input().upper()
count = [0] * 26

for i in range(26):
    letter = chr(i + ord('A'))
    count[i] = word.count(letter)
    
if count.count(max(count)) > 1:
    print('?')
else:
    print(chr(ord('A') + count.index(max(count))))