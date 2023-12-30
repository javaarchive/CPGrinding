import sys
 
input = sys.stdin.readline

hits = {}

T, C = list(map(int, input().split(" ")))
targets = list(map(int, input().split(" ")))

targets_set = set(targets)

instructions = input()

def run(override, char):
    score = 0
    pos = 0
    default_shot_alr = set()

    t = 0

    for instruct in instructions:
        if t == override:
            instruct = char
        if instruct == "F":
            if pos in targets_set and not pos in default_shot_alr:
                score += 1
                default_shot_alr.add(pos)
            if not pos in hits:
                hits[pos] = [t]
            else:
                hits[pos].append(t)
        elif instruct == "R":
            pos += 1
        elif instruct == "L":
            pos -= 1
        else:
            sys.stderr.write("WTF")
        t += 1

    return score

ALTS = ["F", "R", "L"]

ans = run(-1, "x")

for i in range(C):
    instruct = instructions[i]
    choices = filter(lambda x: x != instruct,ALTS[:])
    for alt in choices:
        ans = max(ans, run(i, alt))

print(ans)