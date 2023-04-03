#include <bits/stdc++.h>

using namespace std;
#define fto(i,a,b) for(int i=a;i<=b;++i)
#define fdo(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 998244353
#define SZ(x) ((int)(x).size())

const int N=2e5+5;
bitset<32>tt1;
bitset<32>tt2;
int n,a[N],b[N],tmp3;
int rs;
int tim(int pos1,int pos2)
{
    tt1=bitset<32>(pos1);
    tt2=bitset<32>(pos2);
    rs=0;
    fdo(i,29,0)
    {
        int tmp;
        if(tt2[i]==1) tmp=(tt1[i]^tt2[i]);
        else tmp=0;
        rs=rs*2+tmp;
    }
    return rs;
}
void Solve()
{
    tmp3=a[1];
    fto(i,2,n)
    {
        b[i]=tim(a[i],tmp3);
        tmp3=(a[i]^b[i]);
    }
    fto(i,1,n) cout<<b[i]<<' ';
    cout<<'\n';
}
#undef int
int main()
{
    //freopen("test.inp","r",stdin);
    int Test;
    cin>>Test;
    fto(iTest,1,Test)
    {
      cin>>n;
      fto(i,1,n) cin>>a[i];
      b[1] = 0;
    	Solve();
    }
}