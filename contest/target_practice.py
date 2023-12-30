import sys
 
input = sys.stdin.readline

hits = {}

T, C = list(map(int, input().split(" ")))
targets = list(map(int, input().split(" ")))

targets_set = set(targets)

instructs = input()

default_score = 0
pos = 0
score_history = []

effective_shot_times = set()

default_shot_alr = set()

t = 0

hypo = {}

for instruct in instructs:
    if instruct == "F":
        if pos in targets_set and not pos in default_shot_alr:
            default_score += 1
            default_shot_alr.add(pos)
            effective_shot_times.add(t)
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
    score_history.append(default_score)
    t += 1

ans = default_score

suggestions = {}

for t in targets:
    for delta in [-2,-1,1,2]:
        new_pos = t + delta
        if new_pos in hits:
            for src_time in hits[new_pos]:
                if not src_time in suggestions:
                    suggestions[src_time] = []
                suggestions[src_time].append(delta)

print(suggestions)