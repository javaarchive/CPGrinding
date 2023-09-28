import sys # orz ryan
input = sys.stdin.readline # orz ryan

T = int(input())

masks = [
    # striaghts
    [
        [0,0],
        [0,1],
        [0,2]
    ],[
        [1,0],
        [1,1],
        [1,2]
    ],[
        [2,0],
        [2,1],
        [2,2]
    ],
    [
        
        [0,0],
        [1,0],
        [2,0]
    ],
    [
        
        [0,1],
        [1,1],
        [2,1]
    ],
    [
        
        [0,2],
        [1,2],
        [2,2]
    ],
    # crosses
    [
        
        [0,0],
        [1,1],
        [2,2]
    ],
    [
        
        [0,2],
        [1,1],
        [2,0]
    ]
]

assert len(masks) == 8

for _ in range(T):
    board = [
        input(),
        input(),
        input()
    ]
    found = False
    for pattern in masks:
        uniq = set()
        for point in pattern:
            uniq.add(board[point[0]][point[1]])
        if len(uniq) == 1 and board[pattern[0][0]][pattern[0][1]] != ".":
            p = pattern[0]
            print(board[p[0]][p[1]])
            found = True
            break
    if not found:
        print("DRAW")