#include<bits/stdc++.h>
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
const int N=100005;
int T;
int n,q[N],a[N],D[N];
int main()
{
   // freopen("test.inp","r",stdin);
    cin>>T;
    fto(iTest,1,T)
    {
        cin>>n;
        fto(i,1,n) cin>>q[i];
        a[1]=q[1];
        D[q[1]]=true;
        bool kt=true;
        int l=1;
        fto(i,2,n)
        {
            if(q[i]!=q[i-1])
            {
                a[i]=q[i];
                D[q[i]]=true;
            }
            else
            {
                while(D[l])
                {
                    l++;
                }
                if(l>q[i]) {kt=false;break;}
                D[l]=true;
                a[i]=l;
            }
        }
        fto(i,1,n) D[i]=false;
        if(!kt) {cout<<-1<<'\n';continue;}
        fto(i,1,n) cout<<a[i]<<' ';
        cout<<'\n';
    }
}