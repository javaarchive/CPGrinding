import sys
 
input = sys.stdin.readline

N, K = list(map(int, input().split(" ")))

def make_pair(x,y):
    if x > y:
        return (y,x)
    else:
        return (x,y)
    
A = list(map(int, input().split(" ")))
B = list(map(int, input().split(" ")))

def shiftDiff(a,b):
    return (b - a + K) % K

def solve(A, B):
    sA = set(A)
    sB = set(B)
    invIndexA = {}
    invIndexB = {}
    for i in range(K):
        invIndexA[A[i]] = i
        invIndexB[B[i]] = i
    
    unref = N - len(sA.union(sB))
    ans = unref

    connsA = list()
    connsB = list()

    AA = {}
    rAA = {}
    BB = {}
    rBB = {} 
    for i in range(K):
        connsA.append(make_pair(A[i], A[(i + 1) % K]))
        AA[A[i]] = A[(i + 1) % K]
        rAA[A[(i + 1) % K]] = A[i]

    for i in range(K):
        connsB.append(make_pair(B[i], B[(i + 1) % K]))
        BB[B[i]] = B[(i + 1) % K]
        rBB[B[(i + 1) % K]] = B[i]

    setA = set(connsA)
    setB = set(connsB)

    chained = False

    # 1 2 3 4 5 6 7 8
    # 1 2 3 4 6 7 8 5

    visited = set()

    cl_max = 0

    shifts = {}
    for i in range(K + 1):
        shifts[i] = 0

    for i in range(N):
        init_node = i + 1
        backwards = 0
        forwards = 0
        node = init_node
        if node in visited or not (node in AA and node in BB):
            continue
        visited.add(node)
        for j in range(N):
            if rAA[node] == rBB[node] and not rAA[node] in visited:
                backwards += 1
                node = rAA[node]
                visited.add(node)
            else:
                break
        node = init_node
        for j in range(N):
            if AA[node] == BB[node] and not AA[node] in visited:
                forwards += 1
                node = AA[node]
                visited.add(node)
            else:
                break
        clump = forwards + backwards + 1
        # print("clump calc", forwards, backwards)
        # cl_max = max(cl_max, clump)
        # print("CLUMP", clump, "s ", shiftDiff(invIndexA[node], invIndexB[node]))
        shifts[shiftDiff(invIndexA[node], invIndexB[node])] += clump
        # ans += cl_max
    for shift in shifts:
        cl_max = max(cl_max, shifts[shift])
    ans += cl_max
    return ans
print(max(solve(A, B), solve(A, list(reversed(B)))))