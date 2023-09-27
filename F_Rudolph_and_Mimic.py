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


def is_same(fa, fb):
    for t in fb:
        if fb[t] != fa[t]:
            return False
    for t in fa:
        if fb[t] != fa[t]:
            return False
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
    s1 = get_state()
    kill()
    s2 = get_state()
    new_type = None
    s3 = None
    if is_same(build_freq(s1), build_freq(s2)): # scared
        kill()
        s3 = get_state()
        new_type = get_delta_add_type(build_freq(s2), build_freq(s3))
    else:
        s3 = s2
        # early kill type
        new_type = get_delta_add_type(build_freq(s1), build_freq(s2))
    # kill every other type
    victims = []
    # print("NT",new_type)
    # flush()
    for i in range(len(s3)):
        if s3[i] != new_type:
            victims.append(i)
    kill(victims)
    victims.clear()
    s4 = get_state()
    s5 = None
    if is_same(build_freq(s3), build_freq(s4)):
        # it may be scared and not willing to change, no worries we can wait it out
        kill()
        s5 = get_state()
    else:
        s5 = s4
    # it is time to murder the mimic
    for i in range(len(s5)):
        if s5[i] != new_type:
            print("! " + str(i))
            flush()
            break
    # next test case