#include<bits/stdc++.h>
#define int long long
#define fto(i,a,b) for(int i=a;i<=b;++i)
#define fdo(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
const int P=2750135;
const int N=200005;
int n,a[N*2],Boo[P];
int isprime[P],m[P];
vector<int> res;
void sang()
{
    fto(i,2,2750131)
    if(!isprime[i])
    {
        for(int j=i*2;j<=2750131;j+=i)
        if(!isprime[j])
        isprime[j]=max(i,j/i);
    }
    int dem=0;
    fto(i,2,2750131)
    if(!isprime[i])
    {
        dem++;
        m[i]=dem;
        isprime[i]=i;
    }
}
main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
   // freopen("test.inp","r",stdin);
    sang();
    cin>>n;
    fto(i,1,n*2)
    {
        cin>>a[i];
        Boo[a[i]]++;
    }
    sort(a+1,a+1+n*2);
    //cout<<isprime[6];
    fdo(i,n*2,1)
    if(Boo[a[i]]&&isprime[a[i]]!=a[i])
    {
        res.push_back(a[i]);
        --Boo[a[i]];
        --Boo[isprime[a[i]]];
    }
    fdo(i,n*2,1)
    if(Boo[a[i]])
    {
        Boo[a[i]]--;
        Boo[m[a[i]]]--;
        res.push_back(m[a[i]]);
    }
    fto(i,0,res.size()-1)
    cout<<res[i]<<' ';
}