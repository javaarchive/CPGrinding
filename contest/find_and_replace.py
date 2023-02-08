# prototype that is slow

CHARSET = "abcdefghijklmnopqrstuvwxyzABCDERFGHIJKLMNOPQRSTUVWXYZ"

def solve():
    a = input()
    b = input()
    L = len(a)
    used = set()
    assert len(b) == L
    src_to_dest = {}
    dest_to_src = {}

    def check_cycling(c):
        moves = len(CHARSET)
        cur = src_to_dest[]

    for c in CHARSET:
        src_to_dest[c] = set()
        dest_to_src[c] = set()

    for i in range(L):
        used.add(a[i])
        used.add(b[i])
        src_to_dest[a[i]].add(b[i])
        dest_to_src[b[i]].add(a[i])
    for c in CHARSET:
        # a character cannot become multiple characters
        if len(src_to_dest[c]) > 1:
            print(-1)
            return
    # populate unused set
    unused = []
    for c in CHARSET:
        if c not in used:
            unused.append(c)
    
    replaces = 0
    

    print(int(replaces))                

N = int(input())
while N > 0:
    N -= 1
    solve()
