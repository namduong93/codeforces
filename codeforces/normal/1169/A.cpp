#include<bits/stdc++.h>
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int a,b,x,y,n;
vector<int> s1,s2;
int main()
{
    //freopen("test.inp","r",stdin);
    cin>>n>>a>>x>>b>>y;
    //cout<<n<<' '<<a;
    while(a!=x)
    {
        a++;
        if(a>n) a=1;
        s1.push_back(a);
        //cout<<a;
    }
    while(b!=y)
    {
        b--;
        if(b==0) b=n;
        s2.push_back(b);
    }
    fto(i,0,min(s1.size(),s2.size())-1)
    if(s1[i]==s2[i]) {cout<<"YES";return 0;}
    cout<<"NO";
}