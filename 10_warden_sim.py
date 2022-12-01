import random
import math
BOUND = -1000000
sx = random.randint(-BOUND,BOUND)
sy = random.randint(-BOUND,BOUND)

def dist(ax, ay, bx, by):
    return math.sqrt((ax-bx)**2 + (ay-by)**2)

for i in range(151):
    [cmd, xs, ys] = input().split(' ')
    x = float(xs)
    y = float(ys)
    if cmd == 'P':
        print(dist(0,0,x,y) + dist(x,y,sx,sy))
    elif cmd == 'B':
        if dist(x,y,sx,sy) > 100:
            print("WRONG_ANSWER")
        else:
            print("CORRECT")

print("WA")