import sys
input = sys.stdin.readline

def solve():
    n = int(input().strip())
    limit = 1
    step = 1
    while limit < n:
        limit += 6 * step
        step += 1
    print(step)

if __name__ == "__main__":
    solve()