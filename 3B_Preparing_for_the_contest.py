import sys
 
input = sys.stdin.readline

def solve():
    # depression arc simulator
    N, K = list(map(int, input().split(" ")))
    ans = []
    ans.extend(range(N - K, N + 1, 1))
    ans.extend(range(N - K - 1, 0, -1))
    print(" ".join(map(str, ans)))

for _ in range(int(input())):
    solve()