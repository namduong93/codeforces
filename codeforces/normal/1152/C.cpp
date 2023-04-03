#include<bits/stdc++.h>
#define int long long
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int a,b;
int k;
int ans,pos,res=22345678901234567890;
vector<int> s;
main()
{
    cin>>a>>b;
    if(a==b) {cout<<0;return 0;}
    k=abs(a-b);
    fto(i,1,trunc(sqrt(k)))
    if(k%i==0)
    {
        s.push_back(i);
        if(i*i!=k) s.push_back(k/i);
    }
    //sort(s.begin(),s.end());
    fto(i,0,s.size()-1)
    {
        int tmp=s[i];
        if(a%tmp==0)
        {
            //cout<<tmp<<' ';
            ans=(a*b)/__gcd(a,b);
            if(ans<res)
                res=ans,pos=0;
        }
        else
        {
            ans=((tmp-a%tmp+a)*(tmp-b%tmp+b))/__gcd((tmp-a%tmp+a),(tmp-b%tmp+b));
            //if(tmp==5) cout<<ans<<' ';
            if(ans<res)
            {
                res=ans;
                pos=tmp-a%tmp;
            }
        }
    }
    cout<<pos;
   // cout<<__gcd(948248263,533435438);
}