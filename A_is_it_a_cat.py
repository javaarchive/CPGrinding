N = int(input())
for i in range(N):
    input() # waste a line
    line = input().lower()
    # todo: write correct solution when not tired. 
    print("YES" if ("me" in line and "eo" in line and "ow" in line and line.startswith("m") and line.endswith("w")) else "NO")