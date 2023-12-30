T = int(input())

def tri(N):
    return (N * (N + 1))/2

def calc(streak, K): # given streak days with good weather calculate the number of stuff satsifying requirements
    # print(streak, K - 1, " -> ", tri(streak) - tri(K - 1))
    if streak < K:
        return 0
    return tri(streak - K + 1)
    # return tri(streak) - tri(K - 1) - (K - 1)


# 1
assert calc(3,3) == 1
# 1 2
assert calc(4,3) == 3
# 


def solve():
    N, K, Q = [int(s) for s in input().split(" ")]
    temps = [int(s) for s in input().split(" ")]
    streak = 0
    ans = 0
    for i in range(N):
        streak += 1
        if temps[i] > Q:
            #if i != 0 and temps[i - 1] <= Q:
            streak -= 1 # don't count this above temp days
            # print("SL",streak)
            if streak >= K:
                ans += calc(streak, K)
            streak = 0
            continue
    # print("FS",streak)
    if streak >= K:
        ans += calc(streak, K)
    print(int(ans))

for _ in range(T):
    solve()