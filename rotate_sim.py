for _ in range(int(input())):
    # N = int(input())
    N, K = [int(s) for s in input().split(" ")]
    arr = []
    for i in range(N):
        arr.append(i + 1)

    # print(arr, " base")

    before = 0
    first = 1

    for i in range(N):
        val = arr[i]
        if val < before:        
            if val == first:
                print("0")
            else:
                print("1")
            first = val
        before = val
        # print("Take",val)
        del arr[i]
        arr.append(val)
        # print(arr)

    # print(arr)
    # print([arr.index(i + 1) for i in range(N)])
    print(arr.index(K) + 1)