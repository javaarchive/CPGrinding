from collections import defaultdict

import sys
def flush():
    sys.stderr.flush()
    sys.stdin.flush()
    sys.stdout.flush()

N = 0 # global var thing?

def get_state():
    return [int(s) for s in input().split()]

def build_freq(state):
    if not state:
        return defaultdict(lambda: 0)
    freqs = defaultdict(lambda: 0)
    for t in state:
        freqs[t] += 1
    return freqs

def get_delta_add_type(fa, fb):
    for t in fb:
        if (fb[t] - fa[t]) > 0:
            return t


def get_delta_del_type(fa, fb):
    for t in fb:
        if (fb[t] - fa[t]) < 0:
            return t


def is_same_as(fa, fb):
    for t in fb:
        if fb[t] != fa[t]:
            return False
    #  for t in fa:
    #     if fb[t] != fa[t]:
    #       return False
    return True


def kill(idxs = []):
    print("- ",end="")
    print(str(len(idxs)) + " ",end="")
    print(" ".join([str(x + 1) for x in idxs]))
    # print()
    flush()


T = int(input())

for _ in range(T):
    N = int(input())
    prev = None
    prev_freq = build_freq(prev)
    ans_found = False
    for iteration in range(5):
        state = get_state()
        cur_freq = build_freq(state)
        predict_freq = build_freq(state)
        if prev and not is_same_as(prev_freq,cur_freq):
            # print(prev_freq, cur_freq)
            added_type = get_delta_add_type(prev_freq, cur_freq)
            if cur_freq[added_type] > 1:
                victims = []
                for i in range(len(state)):
                    if added_type != state[i]:
                        victims.append(i)
                        predict_freq[state[i]] -= 1
                kill(victims)
            else:
                # found answer
                # print("DEBUG",added_type)
                print("! " + str(state.index(added_type) + 1))
                flush()
                ans_found = True
        else:
            # nothing happended or init
            kill()
        prev = state
        prev_freq = predict_freq
        if ans_found:
            break
    