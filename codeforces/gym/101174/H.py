import math

# print(math.log10((32**32)/math.factorial(32)))

# for i in range(64):
#     print(i, math.log2(math.factorial(i)))

d, h = map(int, input().strip().split())

h -= 1

f = [1]

for i in range(1, 64):
    f.append(f[-1]*i)

def gen_cases(prev, dim_left, num_left, product):
    if dim_left == 1:
        product *= f[num_left]
        return {f[h] // product}

    S = set()
    for i in range(prev, math.ceil(num_left/dim_left)+1):
        S = S.union(gen_cases(i, dim_left-1, num_left-i, product * f[i]))
    
    return S


S = gen_cases(0, d, h, 1)

print(*sorted(list(S)), sep='\n')