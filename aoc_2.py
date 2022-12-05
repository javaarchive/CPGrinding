c = {
    "X": 1, # rock 
    "Y": 2, # paper
    "Z": 3, # scissors
    "A": 1,
    "B": 2,
    "C": 3
}
beatBy = [-1,2,3,1]

score = 0

while True:
    line = input()
    if line == "":
        break
    [a,b] = line.split()
    an = c[a]
    bn = c[b]
    score += bn
    if an == bn:
        score += 3
    elif beatBy[an] == bn: # bn beats an
        score += 6
print(score)