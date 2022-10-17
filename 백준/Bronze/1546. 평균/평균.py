size = int(input())
scores = list(map(int, input().split()))
    
print(((sum(scores)/size)/max(scores)) * 100)