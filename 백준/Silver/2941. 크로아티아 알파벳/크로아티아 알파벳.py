word = input()

length = len(word)
Croatia = word.count('c=') + word.count('c-') + word.count('dz=')\
+ word.count('d-') + word.count('lj') + word.count('nj') + word.count('s=') + word.count('z=')

length -= Croatia

print(length)