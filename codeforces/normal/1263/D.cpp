#include<bits/stdc++.h>
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
const int N=2e5+4;
int n,kq;
string a[N];
int dsu[35];
bool Boo[30],havee[30],ch[N][30];
int root(int u)
{
	if(dsu[u] < 0) return u;
	dsu[u] = root(dsu[u]);
	return dsu[u];
}
void Union(int u,int v)
{
    u=root(u);
    v=root(v);
    if(u==v) return ;
    if(dsu[u]<dsu[v]) swap(u,v);
    dsu[u]+=dsu[v];
    dsu[v]=u;
   // if(u==0&&v==1) cout<<u<<' '<<root(1);
}
int main()
{
    //freopen("test.inp","r",stdin);
    cin>>n;
    fto(i,0,'z'-'a') dsu[i]=-1;
    fto(i,1,n)
    {
        cin>>a[i];
        fto(j,0,a[i].length()-1)
        {
            ch[i][a[i][j]-'a']=true;
            havee[a[i][j]-'a']=true;
        }
        fto(ch1,0,'z'-'a')
        fto(ch2,0,'z'-'a')
        if(ch1!=ch2&&ch[i][ch1]&&ch[i][ch2])
        {
            //if(i==3&&ch1==0&&ch2==1) cout<<"cC";
            Union(ch1,ch2);
        }
    }
    fto(i,0,'z'-'a')
    if(havee[i])
    {
        if(!Boo[root(i)]) {Boo[root(i)]=true;kq++;}
    }
    cout<<kq;
}