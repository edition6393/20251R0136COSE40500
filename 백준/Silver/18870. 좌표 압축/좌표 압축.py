import sys

def bsearch(data, target):
    first = -1
    last = len(data)

    while first + 1 < last :
        mid = (first + last) // 2
        if data[mid] >= target:
            last = mid
        else:
            first = mid
    return last

input = sys.stdin.readline
n = int(input())
data = list(map(int, input().strip().split()))


sorted_data = sorted(list(set(data)))
for i in range(n):
    print(bsearch(sorted_data, data[i]), end = ' ')
