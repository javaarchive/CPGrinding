T = int(input())

def binary(x):
    return bin(x)[2:]

def solve():
    N, K = [int(s) for s in input().split(" ")]
    bstr = binary(N)
    buyable = 0
    # bstr = "".join(reversed(bstr))
    bstr_L = len(bstr)
    print(N," ",bstr)
    for i in range(bstr_L): # each bit in money
        if bstr[i] != "1":
            continue
        powerOf2 = N - 1 - i
        if powerOf2 > N: # can outbuy the entire shop
            print(1 << N)
            return
        elif powerOf2 == N: # can buy expensive item or the resto of the store
            print(1 << (N - 1) + 1)
            return
        elif powerOf2 < N:
            # poor case, 
            # 0001001: your money
            # 1111111: products avali
            print(1 << (powerOf2 - 1) + 1)
            return

    # print(bstr)

for _ in range(T):
    solve()