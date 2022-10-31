# codegolf time
def solve():
    N = int(input())
    arr = list(map(int, input().split(" ")))
    seen = set()
    dups = 0
    for x in arr:
        if x in seen:
            dups += 1
        else:
            seen.add(x)
    print(len(arr) - (dups if dups % 2 == 0 else dups + 1))
T = int(input())
for i in range(T):
    solve()