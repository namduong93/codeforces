#include<bits/stdc++.h>
using namespace std;

#define fto(i,a,b) for(int i=a;i<=b;++i)
#define fdo(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 998244353
#define SZ(x) ((int)(x).size())

const int N=100000;
int Test;
int xA,yA,xB,yB,xF,yF;
int main()
{
  //freopen("test.inp","r",stdin);
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  cin>>Test;
  fto(iTest,1,Test)
  {
    cin>>xA>>yA;
    cin>>xB>>yB;
    cin>>xF>>yF;
    int cc=abs(xB-xA)+abs(yB-yA);
    if(xA==xB&&xA==xF)
    {
      if(yF>yA&&yF<yB)cout<<cc+2<<'\n';
      else
      {
        if(yF<yA&&yF>yB) cout<<cc+2<<'\n';
        else cout<<cc<<'\n';
      }
      continue;
    }
    if(yA==yB&&yA==yF)
    {
      if(xF>xA&&xF<xB)cout<<cc+2<<'\n';
      else
      {
        if(xF<xA&&xF>xB) cout<<cc+2<<'\n';
        else cout<<cc<<'\n';
      }
      continue;
    }
    cout<<cc<<'\n';
  }
}