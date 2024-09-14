import sys
import math
input = sys.stdin.readline

def solve():
    split = input().split(" ")
    L, R = int(split[0]), int(split[1])
    DIFF = R - L
    if DIFF == 0:
        print(1)
        return
    begin = max(int(math.sqrt(DIFF * 2)) - 3, 0)
    while DIFF >= ((begin * (begin + 1)) / 2):
        begin += 1

    print(begin)
    return

T = int(input())
for _ in range(T):
    solve()