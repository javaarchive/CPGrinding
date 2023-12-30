import sys
 
input = sys.stdin.readline

def solve():
    a, b = list(map(int, input().split(" ")))
    x1, y1 = list(map(int, input().split(" ")))
    x2, y2 = list(map(int, input().split(" ")))
    origins_1 = set()
    origins_2 = set()
    def add(s, x, y):
        s.add((x + a,y + b))
        s.add((x + a,y - b))
        s.add((x - a,y + b))
        s.add((x - a,y - b))
        s.add((x + b,y + a))
        s.add((x + b,y - a))
        s.add((x - b,y + a))
        s.add((x - b,y - a))
    add(origins_1, x1, y1)
    add(origins_2, x2, y2)
    print(len(origins_1.intersection(origins_2)))

for _ in range(int(input())):
    solve()