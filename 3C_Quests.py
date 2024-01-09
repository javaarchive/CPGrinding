import sys
 
input = sys.stdin.readline

def solve():
    N, K = list(map(int, input().split(" ")))
    arr_a = list(map(int, input().split(" ")))
    arr_b = list(map(int, input().split(" ")))
    ans = 0
    before_sum = 0
    best_repeat = 0
    for i in range(N):
        if i >= K:
            # unreachable
            break
        before_sum += arr_a[i]
        best_repeat = max(arr_b[i], best_repeat)
        exp = best_repeat * (K - i - 1) + before_sum
        ans = max(exp, ans)
    print(ans)

for _ in range(int(input())):
    solve()