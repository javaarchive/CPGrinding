import math

T = int(input())

table = [
    [0,0],
    [1,0],
    [0,1],
    [1,1]
] # mod 4

def get_odds(N):
    odds = []
    for i in range(N):
        if i % 2 == 0:
            odds.append(i + 1)
    return odds

def encode_binary(inp):
    out = []
    num = inp
    while num > 0:
        out.append(num % 2)
        num -= num % 2
        num = int(num / 2)
    return out

# print(encode_binary(69))

def generate_reinsertions(N, K):
    takes = get_odds(N)
    for t in takes:
        yield t
    selection = list(encode_binary(N)) #table[N % 4]
    # selection[-1] = 0 # this is needed for some reason
    #for d in selection:
    #    print(d)
    #new_takes = []
    #print(takes,selection)
    #for i in range(selection[0], len(takes), 2):
    #    new_takes.append(takes[i])
    #    yield takes[i]
    #takes = new_takes
    #new_takes = []
    #for i in range(selection[1], len(takes), 2):
    #    new_takes.append(takes[i])
    #    yield takes[i]
    #takes = new_takes
    # take 1st of every 2 now
    #for p in range(1,6969):
    #    every = 1 << p # 2 to the power of p
    #    if every > len(takes):
    #        break
    #    for i in range(0, len(takes), every):
    #        yield takes[i]
    for parity in selection:
        new_takes = []
        for i in range(parity, len(takes), 2):
            new_takes.append(takes[i])
            yield takes[i]
        takes = new_takes
    
def solve_2(N, K):
    last_reinsert = {}
    counter = 0
    odds = get_odds(N)
    evens_count = math.floor(N / 2) # for offsetting
    for card in generate_reinsertions(N, K):
        # print(counter, " sim -> ", card)
        #print("Take",card) # for diffing
        last_reinsert[card] = counter
        counter += 1
    # print(last_reinsert)
    back_half = odds[:]
    back_half.sort(key = lambda c: last_reinsert[c])
    # print("gen bh: ",back_half)
    return int(1 + back_half.index(K) + int(evens_count))

def solve():
    N, K = [int(s) for s in input().split(" ")]
    if K % 2 == 0:
        print(int(K / 2))
    else:
        print(solve_2(N, K))

for T in range(T):
    solve()