N = int(input())
words = input().split(" ")

for size in range(int(N/2),0,-1):
    for i in range(N):
        if (i + size) >= N:
            continue
        phrase = words[i:i+size+1]
        # count phrase amounts
        
