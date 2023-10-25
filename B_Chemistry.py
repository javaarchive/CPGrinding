T = int(input())

from collections import defaultdict

def cp(f):
    s = 0
    for k in f:
        s += len(k)
    return s

def solve():
    N, K = list(map(int, input().split(" ")))
    l = input()

    f = dict()
    ch = set()
    for c in l:
        if not c in f:
            f[c] = 1
        else:
            f[c] += 1
        ch.add(c)
    if (N - K) % 2:
        subs = 0
        for char in c:
            if f[char] % 2 == 1:
                subs += 1
                f[char] -= 1
        # centerpiece ok
        subs -= 1
        # print(subs)
        if subs == K:
            print("YES")
            return
        if subs > 0 and subs % 2 == 0:
            # remove random stuffs
            pairs = cp(f)

        print("NO") 
    else:
        subs = 0
        for char in c:
            if f[char] % 2 == 1:
                subs += 1
                f[char] -= 1
        # print(subs)
        if subs == K:
            print("YES")
            return
        
        if subs > 0 and subs % 2 == 0:
            # remove random stuffs
            pairs = cp(f)

        print("NO")

for _ in range(T):
    solve()
    # print("============")
    