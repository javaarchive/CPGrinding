count = 0
maxcount = -1

while True:
    p = input()
    if p == "END":
        if count > maxcount:
            maxcount = count
        print("Max is",maxcount)
        exit()
    elif p == "":
        if count > maxcount:
            maxcount = count
        count = 0
    else:
        count += int(p)