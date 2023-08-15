[a_s, b_s, x_s] = input().split(" ")
A = int(a_s)
B = int(b_s)
X = int(x_s)
# x % 2 == 0 111110111111
s = ""
if X % 2 == 1:
    # For example 3
    # 0001011111
    # 5
    # 0001010111
    repeats = (X + 1)/2
    A -= repeats
    B -= repeats
    for i in range(int(A)):
        s += "0"
    for i in range(int(repeats)):
        s += "01"
    for i in range(int(B)):
        s += "1"
else:
    # x is a multiple of 2
    # 4
    # "01010"
    # 4
    # 3 3 4
    # "0101110"
    zeros = int(X / 2)
    A -= zeros
    B -= zeros
    s += "0" * int(A - 1)
    # s += "1"
    s += (int(X/2)) * "01" #  000...0101111
    s = s[:-1]
    s += "1" * int(B + 1)
    s += "0"
print(s)    