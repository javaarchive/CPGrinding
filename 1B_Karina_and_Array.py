
import pprint

def solve():
    N = int(input())
    arr = list(map(int,input().split(" ")))
    s = sorted(list(set(arr)))
    
    freqs = {}
    for i in range(N):
        value = arr[i]
        if not value in freqs:
            freqs[value] = 1
        else:
            freqs[value] += 1
    
    neg = ((s[0])*(s[0])) if freqs[s[0]] > 1 else (s[0] * s[1])
    pos = ((s[-1])*(s[-1])) if freqs[s[-1]] > 1 else (s[-1] * s[-2])

    # print("MAX",neg,pos)

    print(max(neg,pos))


for _ in range(int(input())):
    solve()