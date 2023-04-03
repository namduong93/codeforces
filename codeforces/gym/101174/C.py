d = int(input())
r = int(input())
t = int(input())

def tri(i):
    return i * (i-1) / 2


for i in range(1000):
    if tri(i) + tri(i-d) - 9 == r + t:
        age = i
        break

print(int(r - (tri(age) - 6)))