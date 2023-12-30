
import pprint

def solve():
    [N, M, K] = list(map(int, input().split(" ")))
    total = 0
    weights = []
    for i in range(N):
        [weight, count] = list(map(int, input().split(" ")))
        total += count
        weights.append(weight)
        
    

for _ in range(int(input())):
    solve()