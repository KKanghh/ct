alphabet = [-1] * 26

word = input()
word_set = set(word)

for letter in word:
    alphabet[ord(letter) - ord('a')] = word.index(letter)
    
print(*alphabet)