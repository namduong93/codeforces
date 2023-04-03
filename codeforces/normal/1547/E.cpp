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

const int oo=2000000000;
const int N=300004;
int Min1[4*N],Min2[4*N];
int pos[N];
void build1(int x,int l,int r)
{
    if(l==r) {Min1[x]=pos[l]-l;return ;}
    build1(x*2,l,(l+r)/2);
    build1(x*2+1,(l+r)/2+1,r);
    Min1[x]=min(Min1[x*2],Min1[x*2+1]);
}
void build2(int x,int l,int r)
{
    if(l==r) {Min2[x]=pos[l]+l;return ;}
    build2(x*2,l,(l+r)/2);
    build2(x*2+1,(l+r)/2+1,r);
    Min2[x]=min(Min2[x*2],Min2[x*2+1]);
}
int get_min1(int x,int l,int r,int d,int c)
{
  if(c<l||r<d) return oo;
  if(d<=l&&r<=c) return Min1[x];
  return min(get_min1(x*2,l,(l+r)/2,d,c),get_min1(x*2+1,(l+r)/2+1,r,d,c));
}
int get_min2(int x,int l,int r,int d,int c)
{
  if(c<l||r<d) return oo;
  if(d<=l&&r<=c) return Min2[x];
  return min(get_min2(x*2,l,(l+r)/2,d,c),get_min2(x*2+1,(l+r)/2+1,r,d,c));
}

int Test;
int a[N],t[N];
int main()
{
  //freopen("test.inp","r",stdin);
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  cin>>Test;
  fto(iTest,1,Test)
  {
    int n,k;
    cin>>n>>k;
    fto(i,1,n) pos[i]=oo;
    fto(i,1,4*n) Min1[i]=Min2[i]=oo;
    fto(i,1,k) cin>>a[i];
    fto(i,1,k) {cin>>t[i];pos[a[i]]=t[i];}
    build1(1,1,n);
    build2(1,1,n);
    fto(i,1,n)
    {
      int tmp=oo;
      if(i!=1) tmp=min(tmp,get_min1(1,1,n,1,i-1)+i);
      if(i!=n) tmp=min(tmp,get_min2(1,1,n,i+1,n)-i);
      tmp=min(tmp,pos[i]);
      cout<<tmp<<' ';
    }
    cout<<'\n';
  }
}