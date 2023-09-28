import sys
input=sys.stdin.readline

T = int(input())
for _ in range(T):
    N = int(input())
    ans = 0
    for i in range(N):
        iter = map(int,input().split(" "))
        H = next(iter)
        L = next(iter)
        if H > L:
            ans += 1
    print(ans)