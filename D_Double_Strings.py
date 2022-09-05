def solve():
    strs = []
    strs_set = set()
    N = int(input())
    for i in range(N):
        str = input()
        strs_set.add(str)
        strs.append(str)
    for i in range(N):
        length = len(strs[i])
        ans = 0
        # print("BEGIN: " + strs[i])
        for s in range(1, length):
            # split at s
            a = strs[i][:s]
            b = strs[i][s:]
            # print("CHECK " + a + " and " + b)
            # both have
            if a in strs_set and b in strs_set:
                ans = 1
                break
        print(ans, end='')
    print()
NN = int(input())
for i in range(NN):
    solve()