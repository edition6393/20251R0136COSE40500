N = int(input())
k = int(input())

mid = N * N // 2
start, end = 1, N * N

while start + 1 < end:
    mid = (start + end) // 2
    same = 0
    pos = mid // N
    count = mid // N * N

    for num in range(pos + 1, N + 1):
        count = count + mid // num
        if mid % num == 0:
            same = same + 1
    # if mid % N == 0:
    #     same = same // 2 + 1
    # else:
    #     same = same // 2
    if count - same < k <= count:
        end = mid
        break
    elif k > count:
        start = mid
    else:
        end = mid

if k == 1:
    print("1")
elif k == N * N:
    print(f"{N * N}")
else:
    print(end)