#include<bits/stdc++.h>
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int t,n,pos;
string str;
int main()
{
    cin>>t;
    while(t--)
    {
        pos=-1;
        cin>>n;
        cin>>str;
        str=' '+str;
        fto(i,1,n)
        if(str[i]=='8') {pos=i-1;break;}
        if(pos!=-1&&n-pos>=11) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
}