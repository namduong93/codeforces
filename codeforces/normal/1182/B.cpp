#include<bits/stdc++.h>
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
const int N=505;
int h,w;
int gg;
char ch[N][N];
bool check(int s,int t)
{
    if(ch[s-1][t]!='*'||ch[s][t-1]!='*'||ch[s][t+1]!='*'||ch[s+1][t]!='*') return false;
    int dem=1;
    int tmps=s;
    int tmpt=t;
    while(tmps>1&&ch[tmps-1][tmpt]=='*')
    {
        dem++;
        --tmps;
    }
    tmps=s,tmpt=t;
    while(tmps<h&&ch[tmps+1][tmpt]=='*')
    {
        dem++;
        ++tmps;
    }
    tmps=s,tmpt=t;
    while(tmpt>1&&ch[tmps][tmpt-1]=='*')
    {
        dem++;
        --tmpt;
    }
    tmps=s,tmpt=t;
    while(tmpt<w&&ch[tmps][tmpt+1]=='*')
    {
        dem++;
        ++tmpt;
    }
    tmps=s,tmpt=t;
    if(dem==gg) return true;
    return false;
}
int main()
{
    //freopen("test.inp","r",stdin);
    cin>>h>>w;
    fto(i,1,h)
    fto(j,1,w)
    {
        cin>>ch[i][j];
        if(ch[i][j]=='*') gg++;
    }
    if(h<3||w<3) {cout<<"NO";return 0;}
    fto(i,2,h-1)
    fto(j,2,w-1)
    if(ch[i][j]=='*')
    {
        if(check(i,j)==true) {cout<<"YES";return 0;}
    }
    cout<<"NO";
    return 0;
}