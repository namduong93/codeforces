N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
best = -1
for i in range(N):
    best = max(best, min(abs(A[i] - val) for val in B))
print(best)