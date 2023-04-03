#include<bits/stdc++.h>
#define fto(i,a,b) for(int i=a;i<=b;++i)
bool Boo[50];
using namespace std;
int main()
{
    //freopen("test.inp","r",stdin);
    int Test;
    cin>>Test;
    while(Test--)
    {
        int n;string str;
        cin>>n;
        cin>>str;
        fto(i,0,30) Boo[i]=false;
        int kq=1;
        fto(i,0,n-1)
        {
            if(i==0||str[i]!=str[i-1])
            {
                if(Boo[str[i]-'A']) kq=0;
                Boo[str[i]-'A']=true;
            }
        }
        if(kq==0) cout<<"NO"<<'\n';
        else cout<<"YES"<<'\n';
    }
}