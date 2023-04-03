#include<bits/stdc++.h>
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int T,n,a,b,c,d,e,f;
int rs;
string s;
int kq[105];
int main()
{
    //freopen("test.inp","r",stdin);
    cin>>T;
    fto(iTest,1,T)
    {
        cin>>n;
        //cout<<n;
        cin>>a>>b>>c;
        cin>>s;
        s=' '+s;
        d=e=f=0;
        fto(i,1,n)
        {
            if(s[i]=='R') d++;
            if(s[i]=='P') e++;
            if(s[i]=='S') f++;
        }
        rs=0;
        rs=min(a,f)+min(b,d)+min(c,e);
        if(rs>=n/2+(n%2!=0))
        {
            cout<<"YES"<<'\n';
            fto(i,1,n) kq[i]=0;
            fto(i,1,n)
            {
                if(s[i]=='S'&&a!=0) {kq[i]=1;a--;}
                if(s[i]=='P'&&c!=0) {kq[i]=3;c--;}
                if(s[i]=='R'&&b!=0) {kq[i]=2;b--;}
            }
            fto(i,1,n)
            if(kq[i]==0)
            {
                if(a!=0) {cout<<'R';a--;}
                else {
                    if(b!=0) {cout<<'P';b--;}
                    else {cout<<'S';c--;}
                }
            }
            else {if(kq[i]==1)cout<<'R';if(kq[i]==2) cout<<'P';if(kq[i]==3) cout<<'S';}
            cout<<'\n';
        }
        else cout<<"NO"<<'\n';
    }
}