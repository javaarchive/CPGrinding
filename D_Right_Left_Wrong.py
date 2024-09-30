import sys
input = sys.stdin.readline

def solve():
    ps = [0]    
    
    N = int(input())
    vals = list(map(int, input().split(" ")))
    dirs = input()
    L = []
    R = []

    for i in range(N):
        if "L" == dirs[i]:
            L.append(i)
            
    for i in range(N, 0, -1):
        if "R" == dirs[i]:
            R.append(i)
    
    L = list(reversed(L))
    R = list(reversed(R))
    
    psum = 0  
    for i in range(N):
        psum += vals[i]
        ps.append(psum) 

    sum = 0
    
    while True:
        if len(L) == 0 or len(R) == 0:
            break
        l = L.pop()
        r = R.pop()
        # print(l, " ", r)
        
        if l < r:
            # query ps
            sum += ps[r + 1] - ps[l]    
        else:
            break
    print(sum)
    
T = int(input())
for _ in range(T):
    solve()