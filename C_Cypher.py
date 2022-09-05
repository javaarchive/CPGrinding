def solve():
    N = int(input())
    initial = list(map(int,input().split(" ")))
    for i in range(N):
        instructs = input().split(" ")[1]
        print(str((initial[i] + sum([(-1 if c == "U" else 1) for c in instructs])) % 10) + " ",end="")
    print()
for i in range(int(input())):
    solve()