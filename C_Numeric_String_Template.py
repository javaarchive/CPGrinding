import sys
input = sys.stdin.readline

def solve():
    N = int(input())
    pattern = list(map(int, input().strip().split(" ")))
    M = int(input())
    # print("TC")
    for _ in range(M):
        line = input().strip()
        L = len(line)
        # permute ordered pairs
        if L != len(pattern):
            print("NO")
            continue
        # print(N,len(pattern), " ", L, repr(line), repr(pattern))
        EXIT = False
        for i in range(L):
            for j in range(i+1, L):
                key_a = pattern[i]
                key_b = pattern[j]
                if key_a != key_b:
                    if line[i] == line[j]:
                        print("NO")
                        EXIT = True
                        break
                else:
                    if line[i] != line[j]:
                        print("NO")
                        EXIT = True
                        break
            if EXIT:
                continue
                        
        print("YES")
        
    
    
T = int(input())
for _ in range(T):
    solve()