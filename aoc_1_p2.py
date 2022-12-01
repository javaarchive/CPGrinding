count = 0
maxcount = -1

elves = []


while True:
    p = input()
    if p == "END":
        elves.append(count)
        print("Sum",sum(sorted(elves,reverse=True)[:3]))
        exit()
    elif p == "":
        elves.append(count)
        count = 0
    else:
        count += int(p)