import sys

def solve():
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    a = data[1:n+1]

    mp = {}
    for i in range(n):
        s = a[i][:-1]
        x = int(s)
        mp[i] = (x, a[i][-1])

    path = []
    res = float('-inf')
    choose = 1

    for i in range(n):
        vst = [False] * (n + 1)
        cur_path = []
        u = i
        point = 0
        while not vst[u]:
            cur_path.append(u)
            vst[u] = True
            x, c = mp[u]

            if c == '+':
                point += x
            elif c == '-':
                point -= x
            elif c == '*':
                point *= x
            else:
                point //= x

            u = x

        if point > res:
            res = point
            path = cur_path
            choose = i
        elif point == res and len(cur_path) < len(path):
            path = cur_path
            choose = i

    print(choose)
    print(res)
    print("->".join(map(str, path)))


if __name__ == "__main__":
    solve()
