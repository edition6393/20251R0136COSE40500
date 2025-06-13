import sys
input = sys.stdin.readline

def swap(a, b, c, d):
    if a > b:
        return b, a, d, c
    return a, b, c, d

def zero_check(c1, c2, b1, b2, a1, a2):
    if (c1, c2) == (0, 0):
        return 1
    if not (b1, b2) == (0, 0) and c2 * b1 == c1 * b2:
        if b1 * c2 - b2 * c1 == 0:
            return 1
        return 0
    if not (a1, a2) == (0, 0) and c2 * a1 == c1 * a2:
        if a1 * c2 - a2 * c1 == 0:
            return 1
        return 0
    return 0

def intersection_check(x, y, s1x, e1x, s1y, e1y, s2x, e2x, s2y, e2y):
    if not (s1x <= x <= e1x):
        return 0
    if not (e1y >= s1y and s1y <= y <= e1y or s1y > e1y and e1y <= y <= s1y):
        return 0
    if not (s2x <= x <= e2x):
        return 0
    if not (e2y >= s2y and s2y <= y <= e2y or s2y > e2y and e2y <= y <= s2y):
        return 0
    return 1


def solve():
    x1, y1, x2, y2 = map(int, input().split())
    x3, y3, x4, y4 = map(int, input().split())
    s1x, e1x, s1y, e1y = swap(x1, x2, y1, y2)
    s2x, e2x, s2y, e2y = swap(x3, x4, y3, y4)
    d1, d2 = x1 * y2 - x2 * y1, x3 * y4 - x4 * y3
    c1, c2 = d1, d2

    a1, b1 = y2 - y1, x1 - x2
    a2, b2 = y4 - y3, x3 - x4
    
    d = a1 * b2 - b1 * a2
    if d == 0:
        if c1 * c2 == 0 and c1 + c2 != 0:
            print(0)
            return
        if zero_check(c1, c2, b1, b2, a1, a2):
            if (b1, b2) == (0, 0):
                ts1y, te1y, ts1x, te1x = swap(y1, y2, x1, x2)
                ts2y, te2y, ts2x, te2x = swap(y3, y4, x3, x4)
                if te1y == ts2y and ts1y < te2y:
                    print(1)
                    print(f"{te1x} {te1y}\n")
                    return
                elif ts1y == te2y and ts2y < te1y:
                    print(1)
                    print(f"{ts1x} {ts1y}\n")
                    return
                elif ts1y <= ts2y <= te1y or ts1y <= te2y <= te1y:
                    print(1)
                    return
                elif ts2y <= ts1y <= te2y or ts2y <= te1y <= te2y:
                    print(1)
                    return
                print(0)
                return
            elif e1x == s2x and s1x < e2x:
                print(1)
                print(f"{e1x} {e1y}")
                return
            elif s1x == e2x and s2x < e1x:
                print(1)
                print(f"{s1x} {s1y}")
                return       
            elif s1x <= s2x <= e1x or s1x <= e2x <= e1x:
                print(1)
                return
            elif s2x <= s1x <= e2x or s2x <= e1x <= e2x:
                print(1)
                return
            else:
                print(0)
                return
        else:
            print(0)
            return
    xd, yd = b2 * c1 - b1 * c2, c2 * a1 - c1 * a2
    x, y = xd / d, yd / d
    if intersection_check(x, y, s1x, e1x, s1y, e1y, s2x, e2x, s2y, e2y): 
        print(1)
        print(f"{x} {y}")
        return
    print(0)
    return

if __name__ == "__main__":
    solve()