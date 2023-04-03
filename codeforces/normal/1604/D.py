""" 
    author:  namduong93
    created: unknown  
    complexity: unknown
    Codeforces: codeforces.com
"""
"""
import sys
sys.stdin = open('test.inp', 'r') 
sys.stdout = open('test.out', 'w')
"""

x=y=0

def Input():
    global x,y
    x, y=map(int,input().split())

def Solve():
    if(x==y):
        print(x)
    else:
        if(x>y):
            print(x+y)
        else:
            print(((y//x)*x+y)//2)

Test=int(input(""))
for iTest in range(Test):
    Input()
    Solve()