import sys
f = open(sys.argv[1], "r")
num_strings = f.read().strip().split(" ")
evens = []
odds = []
counter = 0
for numstr in num_strings:
    if counter % 2 == 0:
        evens.append(int(numstr.replace("\n","")))
    else:
        odds.append(int(numstr.replace("\n","")))
    counter += 1
print("Checking Distinctness")
if not len(evens) == len(set(evens)):
    print("BAD: EVEN DUPLICATE ",len(evens) - len(set(evens)), sum(evens) - sum(list(set(evens))))
    exit(1)
if not len(odds) == len(set(odds)):
    print("BAD: ODD DUPLICATE",len(odds) - len(set(odds)),  sum(odds) - sum(list(set(odds))))
    exit(1)
print("XORing evens:")
evenXOR = 0
for even in evens:
    evenXOR ^= even
print("Final: ",evenXOR)

print("XORing odds:")
oddXOR = 0
for odd in odds:
    oddXOR ^= odd
print("Final: ",oddXOR)
if oddXOR == evenXOR:
    print("OK")
else:
    print("BAD: INEQUAL")
    exit(1)