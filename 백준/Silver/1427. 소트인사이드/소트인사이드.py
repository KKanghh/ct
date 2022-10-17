word = input()
word = ''.join(sorted(word, key = lambda x: int(x),reverse=True))
print(word)