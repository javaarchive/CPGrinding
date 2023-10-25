T = int(input())

K = "1234567890"

def solve():
    pos = 0
    l = input()
    ans = 0
    for i in range(len(l)):
        ans += 1
        new_pos = K.index(l[i])
        ans += abs(new_pos - pos)
        pos = new_pos
    print(ans)

for _ in range(T):
    solve()
    