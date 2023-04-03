#include<bits/stdc++.h>
#define fto(i,a,b) for(int i=a;i<=b;++i)
#define fdo(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int n;
string str;
vector<int> comp[30];
int si,pos=-1;
int tmppos;
int main()
{
    cin>>n;
    cin>>str;
    fto(i,0,n-1)
    {
        fto(j,str[i]-'a'+1,'z'-'a') comp[j].push_back(i);
    }
    fto(i,0,n-1)
    {
        si=comp[str[i]-'a'].size();
        if(si!=0)
        {
            if(comp[str[i]-'a'][si-1]<i) continue;
            else
            pos=comp[str[i]-'a'][si-1];
        }
        if(pos!=-1)
        {
            cout<<"YES"<<'\n';
            cout<<i+1<<' '<<pos+1;
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}