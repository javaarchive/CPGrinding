
import pprint

def solve():
    [N, T] = list(map(int, input().split(" ")))
    secs = list(map(int,input().split(" ")))
    ents = list(map(int,input().split(" ")))
    arr = []
    for i in range(N):
        arr.append((secs[i], ents[i], i + 1))
    bestIndex = -1
    bestEntertainment = -1
    elTime = 0
    for i in range(N):
        if elTime + arr[i][0] <= T:
            if bestEntertainment < arr[i][1]:
                bestEntertainment = arr[i][1]
                bestIndex = i + 1
        elTime += 1
    print(bestIndex)

for _ in range(int(input())):
    solve()