#include<bits/stdc++.h>
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int t;
string s;
int main()
{
   // freopen("test.inp","r",stdin);
    cin>>t;
    fto(iTest,1,t)
    {
        cin>>s;
        int n=s.length();
        s=' '+s;
        fto(i,1,n)
        {
            if(s[i]=='?')
            {
                for(char ch='a';ch<='c';ch++)
                {
                    if(i-1!=0&&ch==s[i-1]) continue;
                    if(i+1!=n+1&&ch==s[i+1]) continue;
                    s[i]=ch;break;
                }
            }
        }
        bool kt=true;
        fto(i,2,n) if(s[i]==s[i-1]) {kt=false;break;}
        if(!kt) cout<<-1;
        else fto(i,1,n) cout<<s[i];
        cout<<'\n';
    }
}