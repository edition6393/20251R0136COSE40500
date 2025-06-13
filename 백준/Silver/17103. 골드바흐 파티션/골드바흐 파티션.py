import sys
input = sys.stdin.readline

table = [True] * (1000000 + 1)
for i in range(2, int(1000001 ** 0.5) + 2):
    if not table[i]:
        continue
    else:
        for j in range(2 * i, 1000000 + 1, i):
            table[j] = False

primes = []
for i in range(2, 1000000):
    if table[i]:
        primes.append(i)

primes_set = frozenset(primes)

T = int(input())
for _ in range(T):
    n = int(input())
    cnt = 0
    for num in primes:
        if num > n // 2:
            break
        if n - num in primes_set:
            cnt += 1
    print(cnt)