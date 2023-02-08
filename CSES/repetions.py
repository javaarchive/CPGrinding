line = input()
streak = 0
last = " "
best = -1
for i in range(len(line)):
    if line[i] == last:
        streak += 1
    else:
        last = line[i]
        streak = 1
    best = max(streak, best)
print(best)