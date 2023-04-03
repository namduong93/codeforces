import copy
n, d, c = map(int, input().strip().split())
X = set(map(int, input().strip().split()))
Y = set(map(int, input().strip().split()))
Z = X.intersection(Y)
X = X.difference(Z)
Y = Y.difference(Z)
x, y, z = len(X), len(Y), len(Z)
# print(X, Y, Z)
# print(x, y, z)


# setup pascal's triangle
c = [[0]*(n+1) for _ in range(n+1)]

c[0][0] = 1
for i in range(1, n+1):
    c[i][0] = 1
    for j in range(1, n+1):
        c[i][j] = c[i-1][j-1] + c[i-1][j]


# setup grid of possibilities
empty = [[[0 for _ in range(z+1)] for _ in range(y+1)] for _ in range(x+1)]
dp = copy.deepcopy(empty)
dp[x][y][z] = 1
dp2 = copy.deepcopy(empty)

T = 1000
ev = 0
for t in range(1, T+1):
    for i in range(x+1):
        for j in range(y+1):
            for k in range(z+1):
                for _i in range(i+1):
                    for _j in range(j+1):
                        for _k in range(k+1):
                            if _i + _j + _k <= d:
                                dp2[i-_i][j-_j][k-_k] += dp[i][j][k] * c[i][_i] * c[j][_j] * c[k][_k] * c[n-(i+j+k)][d-(_i+_j+_k)] / c[n][d]
    dp = dp2
    dp2 = copy.deepcopy(empty)

    # print(dp)
    for i in range(x+1):
        ev += dp[i][0][0] * t
        dp[i][0][0] = 0

    for j in range(y+1):
        ev += dp[0][j][0] * t
        dp[0][j][0] = 0

print(ev)
    # print(dp)
    # print()