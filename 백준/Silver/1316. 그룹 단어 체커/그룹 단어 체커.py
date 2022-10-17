num = int(input())
answer = num
for i in range(num):     
    word = input()

    letter_set = set(word)

    letter_set.remove(word[0])
    for i in range(1, len(word)):
        if word[i] == word[i - 1]:
            continue
        if word[i] not in letter_set:
            answer -= 1
            break
        letter_set.remove(word[i])
print(answer)