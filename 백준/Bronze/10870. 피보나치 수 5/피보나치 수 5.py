def piv(n):
    if n == 0:
        return 0
    elif n <= 2:
        return 1
    else:
        return piv(n - 1) + piv(n - 2)
    
    
num = int(input())
print(piv(num))