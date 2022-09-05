def solve():
    input() # waste le input
    s = set()
    o = 0
    for c in list(input()):
        o += 1 if c in s else 2
        s.add(c)
    print(o)
N = int(input())
for i in range(N):
    solve()