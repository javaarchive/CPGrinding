T = int(input())


# def ops(a,b,c,split) -> bool:
    # total = (a + b + c)
    # piece = float(total) / float(split)
    # return (a % split == 0) and (b % split == 0) and (c % split == 0)

     


 
def gcd(a, b):
    """Calculate the Greatest Common Divisor of a and b.

    Unless b==0, the result will have the same sign as b (so that when
    b is divided by it, the result comes out positive).
    """
    while b:
        a, b = b, a%b
    return a


def solve():
    a, b, c = list(map(int, input().split(" ")))
    split = gcd(a,gcd(b,c))

    cuts = (a / split) + (b / split) + (c / split) - 3
    
    print("NO" if (cuts > 3) else "YES")

for _ in range(T):
    solve()