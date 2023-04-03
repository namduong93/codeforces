#include <bits/stdc++.h>
#define fto(i,a,b) for(int i=a;i<=b;++i)
#define fdo(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
int Test,n;
string s[102];
map<string,int> Map;
int Pow(int aa,int bb)
{
    int tMap=1;
    if(bb==0) return 1;
    fto(i,1,bb)
    tMap*=aa;
    return aa;
}
int main()
{
    //freopen("test.inp","r",stdin);
    cin>>Test;
    fto(iTest,1,Test)
    {
        Map.clear();
        cin>>n;
        int rs=0;
        fto(i,1,n)
        {
            cin>>s[i];
        }
        fto(i,1,n)           Map[s[i]]++;
        cerr<<"concac";
        fto(i,1,n)
        if (Map[s[i]]>1)
        {
            rs++;
            bool kt=0;
            Map[s[i]]--;
            fdo(cc,3,0)
            for(char ch='0';ch<='9';ch++)
            {
                if (kt==true) continue;
                s[i][cc]=ch;
                if (Map[s[i]]==0) {kt=true;continue;}
            }
            Map[s[i]]=1;
            //cout<<i<<endl;
        }
        cout<<rs<<'\n';
        fto(i,1,n) cout<<s[i]<<'\n';
    }
}