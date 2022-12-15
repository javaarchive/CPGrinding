N = int(input())
while N > 0:
    N -= 1
    year = int(input())
    name = input().lower()
    if len(name) > 50:
        print("INVALID")
        continue
    if year < 2010:
        if "cal" in name or "berkeley" in name:
            print("INVALID")
            continue
    print("VALID")