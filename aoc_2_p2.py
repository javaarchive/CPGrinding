c = {
    "X": 1, # rock 
    "Y": 2, # paper
    "Z": 3, # scissors
    "A": 1,
    "B": 2,
    "C": 3
}
beatBy = [-1,2,3,1]
loseBy = [-1,3,1,2]

score = 0

while True:
    line = input()
    if line == "":
        break
    [a,b] = line.split()
    an = c[a]
    bn = c[b]
    # score += bn
    if b == "X":
        score += loseBy[an]
        # 0 score add 
    elif b == "Y":
        score += 3 # an
        score += an # copy the exact same
    elif b == "Z": # bn beats an
        score += 6
        score += beatBy[an]
print(score)
# 19037 not correct