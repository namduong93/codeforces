#include<bits/stdc++.h>
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int n;
string str;
int f[30];
bool Boo=true;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("text.txt","r",stdin);
    cin>>n;
    cin>>str;
    fto(i,1,9)
    cin>>f[i];
    fto(i,0,str.length()-1)
    {
        if(Boo&&f[str[i]-'0']<=str[i]-'0') cout<<str[i]-'0';
        if(!Boo) cout<<str[i]-'0';
        if(Boo==true&&f[str[i]-'0']>str[i]-'0')
        {
            while(i<=str.length()-1&&f[str[i]-'0']>=str[i]-'0')
            {
                cout<<f[str[i]-'0'];
                i++;
            }
            i--;
            Boo=false;
        }
    }
}