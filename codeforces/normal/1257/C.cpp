#include<bits/stdc++.h>
#define fi first
#define se second
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
const int N=200005;
typedef pair<int,int> pii;
int T,n;
int a[N];
map<int,int> m;
int l,kq;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("test.inp","r",stdin);
    cin>>T;
    fto(iTest,1,T)
    {
        cin>>n;
        fto(i,1,n) cin>>a[i];
        fto(i,1,n) m[i]=0;
        l=0;
        kq=-1;
        fto(r,1,n)
        {
            while(l<=n-1)
            {
                l++;
                m[a[l]]++;
                if(m[a[l]]==2)
                {
                    m[a[l]]--;
                    --l;
                    break;
                }
            }
            int t1=l-r+2;
            int cc=min(kq,t1);
            if(l!=n) kq=(kq==-1)? t1 :cc;
            m[a[r]]--;
        }
        cout<<kq<<'\n';
    }
}