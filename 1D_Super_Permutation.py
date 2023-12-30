import sys
 
input = sys.stdin.readline

def generate(l):
    cur_sum = 0
    N = len(l)
    out = []
    for num in l:
        cur_sum += num
        out.append(cur_sum % N)
    return out

'''
print(generate([
    6, # 0
    5, # 5
    2, # 1
    3, # 4
    4, # 2
    1  # 3
]))
'''

def generator(N):
    for i in range(int(N/2)):
        yield i
        yield N - 1 - i
    if N % 2 == 1:
        yield int((N-1)/2)


def solve():
    N = int(input())
    pos = 0
    ans = []

    if N % 2 == 1 and N >= 3:
        print(-1)
        return

    for t in generator(N):
        delta = t - pos
        if delta <= 0:
            delta += N
        ans.append(str(delta))
        pos = t

    if N % 2 == 1 and len(set(ans)) != len(ans):
        print(-1)
        return


    print(" ".join(ans))

T = int(input())
for _ in range(T):
    solve()