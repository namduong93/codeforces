#include<bits/stdc++.h>
#define fto(i,a,b) for(int i=a;i<=b;++i)
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N=7005;
int n,rs;
vector <int> s1;
map <int,int> cont;
struct ndv
{
    int fi,se;
    bool operator < (const ndv &tmp) const
    {
        if(fi!=tmp.fi) return fi<tmp.fi;
        return se<tmp.se;
    }
};
vector <ndv> s2;
ndv edge[N];
main(){
    //freopen("test.inp","r",stdin);
    cin>>n;
    fto(i,1,n) cin>>edge[i].fi;
    fto(i,1,n) cin>>edge[i].se;
    sort(edge + 1,edge + n + 1);

    fto(i,1,n) cont[edge[i].fi]++;
    fto(i,1,n)
    if (cont[edge[i].fi] > 1)
    {rs+=edge[i].se;s1.push_back(edge[i].fi);}
    else s2.push_back(edge[i]);

    if(s1.size())
	s1.resize(unique(s1.begin(),s1.end())-s1.begin());
	if(s2.size())
    fto(i,0,s2.size()-1)
    {
        bool stop=false;
        ndv t1=s2[i];
        if(s1.size())
        fto(i,0,s1.size()-1)
        if(!stop)
        {
            int t2=s1[i];
            if ((t1.fi&t2)==t1.fi)
            {
                rs+=t1.se;
                stop=true;
            }
        }
    }
	cout <<rs;
}