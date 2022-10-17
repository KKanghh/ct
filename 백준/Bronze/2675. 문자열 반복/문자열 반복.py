all_repeat = int(input())

for i in range(all_repeat):
    word_repeat, word = input().split()
    word_repeat = int(word_repeat)
    for letter in word:
        for j in range(word_repeat):
            print(letter, end = "")
    print()