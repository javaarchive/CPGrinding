

T = int(input())
def solve():
    N, M = list(map(int, input().split(" ")))
    a = input()
    b = input()
    s = a[:]

    if b in a:
        print(0)
        return

    for i in range(5):
        s = s + s
        # print(i, s)
        if b in s:
            print(i + 1)
            return
    print(-1)
    
for _ in range(T):
    solve()