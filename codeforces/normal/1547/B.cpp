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

string str;
int main()
{
  //freopen("test.inp","r",stdin);
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  cin>>Test;
  fto(iTest,1,Test)
  {
    cin>>str;
    int pos=-1;
    fto(i,0,str.length()-1)
    if(str[i]=='a') pos=i;
    if(pos==-1) {cout<<"NO"<<'\n';continue;}
    int pos2=pos;
    int dem=1;
    while(true)
    {
      dem++;
      if(pos==0&&pos2==str.length()-1) {cout<<"YES"<<'\n';break;}
      if(pos!=0&&str[pos-1]-'a'+1==dem) {pos--;continue;}
      if(pos2!=str.length()-1&&str[pos2+1]-'a'+1==dem) {pos2++;continue;}
      cout<<"NO"<<'\n';break;
    }
  }
}