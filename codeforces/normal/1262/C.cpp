#include<bits/stdc++.h>
#define fi first
#define se second
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
typedef pair<int,int> pii;
const int N=2005;
int n,T,k;
string st,tmp;
vector<pii> s;
int main()
{
    //freopen("test.inp","r",stdin);
    cin>>T;
    tmp.resize(N);
    fto(iTest,1,T)
    {
        cin>>n>>k;
        k--;
        cin>>st;
        st=' '+st;
        s.clear();
        fto(i,1,k*2)
        {
            char ch;
            if(i%2==1) ch='(';
            else ch=')';
            fto(j,i,n)
            if(st[j]==ch)
            {
                if(i!=j)
                {
                    s.push_back({i,j});
                    fto(kk,i,j) tmp[kk]=st[kk];
                    fto(kk,i,j) st[kk]=tmp[j-kk+i];
                }
                break;
            }
        }
        fto(i,k*2+1,k*2+(n-k*2)/2)
        {
            fto(j,i,n)
            if(st[j]=='(')
            {
                if(i!=j)
                {
                    s.push_back({i,j});
                    fto(kk,i,j) tmp[kk]=st[kk];
                    fto(kk,i,j) st[kk]=tmp[j-kk+i];
                }
                break;
            }
        }
       // cout<<st;
        cout<<s.size()<<'\n';
        if(s.size())
        fto(i,0,s.size()-1)
        cout<<s[i].fi<<' '<<s[i].se<<'\n';
    }
}