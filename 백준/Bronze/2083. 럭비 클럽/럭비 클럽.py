info = input()

while info != "# 0 0":
    name, age, weight = info.split()
    age = int(age)
    weight = int(weight)
    if age > 17 or weight >= 80:
        print(f'{name} Senior')
    else:
        print(f'{name} Junior')
    info = input()