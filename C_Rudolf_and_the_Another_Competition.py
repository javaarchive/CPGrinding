import sys # orz ryan
input = sys.stdin.readline # orz ryan

T = int(input())

for _ in range(T):
    N, M, H = list(map(int, input().split()))
    # N players, M problems, H time
    solve_state = []
    for i in range(N):
        point_penalty_triplet = [0,0,0] # 0 indicates realtime
        problems = list(map(int, input().split()))
        problems = sorted(problems)
        # fastest first for penalty pointoptimize
        # greedy problem solver
        for p_time in problems:
            if (p_time + point_penalty_triplet[2]) <= H:
                # we can clutch it!
                # print(i, " solves ",p_time)
                point_penalty_triplet[0] += 1 # +1 point
                point_penalty_triplet[1] += (p_time + point_penalty_triplet[1]) # +p_time penalty
                point_penalty_triplet[2] += p_time # advance time
        solve_state.append(point_penalty_triplet)
    players = list(range(N))
    class CursedComprator(int):
        def __lt__(self, other):
            if solve_state[self][0] == solve_state[other][0]:
                if solve_state[self][1] == solve_state[other][1]:
                    # index diffed
                    return super().__lt__(other) #(int(str(self))) < (int(str(other)))
                else:
                    # penalty diffed
                    return solve_state[self][1] < solve_state[other][1]
            else:
                # point diffed
                return solve_state[self][0] > solve_state[other][0]
            # print("LT",self)
    players = sorted(players, key = CursedComprator)
    #for p in players:
    #    print(p, " scored ", solve_state[p][0], " points, with penalty of ",solve_state[p][1], " in ", solve_state[p][2])
    print(players.index(0) + 1)