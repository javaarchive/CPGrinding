# cheesing mod 10 threesum

def solve():
    N = int(input())
    arr = list(map(int, input().split()))
    modded = list(map(lambda x: x % 10, arr))
    freqs = {}
    for m in modded:
        freqs[m] = freqs.get(m, 0) + 1
    tsum = []
    for i in range(10):
        for k in range(min(3, freqs.get(i, 0))):
            tsum.append(i)
    for i in range(len(tsum)):
        for j in range(len(tsum)):
            if i == j:
                continue
            for k in range(len(tsum)):
                if k == i or k == j:
                    continue
                if (tsum[i] + tsum[j] + tsum[k]) % 10 == 3:
                    print("YES")
                    return
    print("NO")
    return

T = int(input())
while T > 0:
    solve()
    T -= 1