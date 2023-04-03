#include<bits/stdc++.h>
#define fi first
#define se second
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
const int N=400005;
typedef pair<int,int> pii;
int n,Test;
int a[N];
vector<int> s;
pii b[N];
int main()
{
    //freopen("test.inp","r",stdin);
    cin>>Test;
    fto(iTest,1,Test)
    {
        cin>>n;
        s.clear();
        int sum=0;
        fto(i,1,n) {cin>>a[i];s.push_back(a[i]);}
        s.resize(unique(s.begin(),s.end())-s.begin());
        int m=s.size();
        fto(i,1,m+2)
        {
            if(i<=m)
            b[i].fi=0,b[i].se=s[i-1];
            else b[i].fi=0;
        }
        if(m<=2)
        {
            cout<<0<<' '<<0<<' '<<0<<'\n';
            continue;
        }
        int run=0;
        fto(i,1,n)
        {
            if(a[i]!=a[i-1]) run++;
            b[run].fi++;
        }
       // b[m+1].fi=b[m+2].fi=0;
        int ht=-1;
        int here=0;

        fto(i,1,m)
        {
            here+=b[i].fi;
            if(here<=n/2) ht=i;
            else break;
        }
        //cout<<ht;
        int g=b[1].fi;
        int s=0;
        int tmp=2;
        while(s<=g&&tmp<=m+1)
        {
            s+=b[tmp].fi;
            tmp++;
        }
        if(tmp==m+2)
        {
            cout<<0<<' '<<0<<' '<<0<<'\n';
            continue;
        }
        if(tmp>ht)
        {
            cout<<0<<' '<<0<<' '<<0<<'\n';
            continue;
        }
        int br=0;
        fto(i,tmp,ht) br+=b[i].fi;
        if(br<=g)
        {
            cout<<0<<' '<<0<<' '<<0<<'\n';
            continue;
        }
        cout<<g<<' '<<s<<' '<<br<<'\n';
    }
}