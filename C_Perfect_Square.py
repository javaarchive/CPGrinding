T = int(input())

# x = y
# y = -x

def rotate(x,y,N):
    origin_x = N/2 - 1/2
    origin_y = N/2 - 1/2
    # print("ORIGIN ",origin_x, origin_y)
    return [
        int(origin_x - (origin_y - y)),
        int(-(x - origin_x) + origin_y),
    ]

# print("TEST")
# print("(3,3)", rotate(3,3,4))
# print("(0,3)", rotate(0,3,4))
# print("(0,0)", rotate(0,0,4))
# print("ROT",rotate(3,3,4))
assert rotate(3,3,4) == [3, 0]

def solve():
    N = int(input())
    arr = []
    for i in range(N):
        arr.append(input())
    # build chains
    origin = [N/2 - 1, N/2 - 1]
    ans = 0
    S = int(N / 2)
    for y in range(S):
        for x in range(S):
            values = []
            coord = [y,x]
            # print(coord)
            for __ in range(4):
                coord = rotate(coord[0], coord[1], N)
                values.append(arr[coord[1]][coord[0]])
            def count(m):
                c = 0
                for v in values:
                    if v == m:
                        c += 1
                return c

            le = 99999999999999

            for v in values:
                case = 0
                skip_case = False
                for v2 in values:
                    if ord(v) < ord(v2):
                        skip_case = True
                        break
                    else:
                        case += ord(v) - ord(v2)
                if not skip_case:
                    # print("C",case)
                    le = min(case, le)
            ans += le
            # print(y,",",x," -> ",le)
    print(ans)
for _ in range(T):
    solve()