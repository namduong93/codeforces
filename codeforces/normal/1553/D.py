#import sys
#sys.stdin = open('test.inp', 'r') 
#sys.stdout = open('test.out', 'w')

n=int(input())
for i in range(0,n):
    a=input()
    b=input()
    a=a[::-1]
    b=b[::-1]
    lenA=len(a)
    b=b+"#"
    Boo=False
    cnt=0
    for i in range(0,lenA):
        if Boo:
            Boo=False
            continue
        if a[i]==b[cnt]:
            cnt=cnt+1
            continue
        Boo=True
    if cnt+1==len(b):
        print("YES")
    else:
        print("NO")