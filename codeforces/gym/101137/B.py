def gcd(a, b):
    if a == 0: return b
    else: return gcd(b % a, a)
    
a, b, c = map(int, input().split())
print(("DEADLOCK", "OK")[a + gcd(b, c) >= b + c])