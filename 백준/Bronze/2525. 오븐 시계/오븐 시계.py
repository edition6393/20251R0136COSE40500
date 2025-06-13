A, B = map(int, input().split())
C = int(input())

m, s = divmod(C, 60)
print((A + m + (B + s) // 60) % 24 , (B + s) % 60)