#include<bits/stdc++.h>
#define int long long
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
map<int,bool> D;
int n,dem;
main()
{
    //freopen("text.txt","r",stdin);
    cin>>n;
    while(!D[n])
    {
        //cout<<n<<' ';
        dem++;
        D[n]=true;
        n++;
        int tmpn=n;
        n=0;
        int sum=0;
        while(tmpn%10==0) tmpn=tmpn/10;
        while(tmpn!=0)
        {
            sum=sum*10+tmpn%10;
            tmpn=tmpn/10;
        }
        while(sum!=0)
        {
            n=n*10+sum%10;
            sum=sum/10;
        }
    }
    cout<<dem;
}