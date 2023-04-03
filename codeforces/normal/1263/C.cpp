#include<bits/stdc++.h>
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int Test;
vector<int> s;
int main()
{
    //freopen("test.inp","r",stdin);
    cin>>Test;
    fto(iTest,1,Test)
    {
        int n;
        s.clear();
        cin>>n;
        fto(i,1,trunc(sqrt(n)))
        {
            if(n/i*(i+1)>n) s.push_back(n/i);
        }
        fto(i,1,trunc(sqrt(n)))
        {
            if((n/i+1)*i>n) s.push_back(i);
        }
        s.push_back(0);
        sort(s.begin(),s.end());
        s.resize(unique(s.begin(),s.end())-s.begin());
        cout<<s.size()<<'\n';
        fto(i,0,s.size()-1) cout<<s[i]<<' ';
        cout<<'\n';
    }
}