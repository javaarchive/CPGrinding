import math

def primeFactors(n):
    pr = []
    # Print the number of two's that divide n
    while n % 2 == 0:
        pr.append(2)
        n = n // 2
         
    # n must be odd at this point
    # so a skip of 2 ( i = i + 2) can be used
    for i in range(3,int(math.sqrt(n))+1,2):
         
        # while i divides n , print i ad divide n
        while n % i== 0:
            pr.append(i)
            n = n // i
             
    # Condition if n is a prime
    # number greater than 2
    if n > 2:
        pr.append(n)
    return pr

