#include<bits/stdc++.h>
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
queue<int> q;
int n,m;
int dem;
bool x[1005];
int main()
{
    cin>>n>>m;
    fto(i,1,n) q.push(i);
    while(m--)
    {
        q.pop();
        int d=q.front();
        q.pop();
        q.push(d);
    }
    while(!q.empty())
    {
        x[q.front()]=true;
        q.pop();
    }
    fto(i,1,n)
    if(x[i]!=0&&x[i-1]==0)
        dem++;
    cout<<dem;
}