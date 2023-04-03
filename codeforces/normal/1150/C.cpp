#include<bits/stdc++.h>
#define int long long
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
const int N=200005;
int n;
bool D[2*N];
int a[N],x[N],d[3];
int sum;
void sang()
{
    D[1]=true;
    fto(i,2,trunc(sqrt(n*2)))
    if(!D[i])
    {
        int j=i*i;
        while(j<=n*2)
        {
            D[j]=true;
            j+=i;
        }
    }
}
main()
{
    cin>>n;
    fto(i,1,n)
    {
        cin>>a[i];
        d[a[i]]++;
    }
    sang();
    if(d[2])
    {
        sum=2;
        d[2]--;
        x[1]=2;
    }
    else
    {
        sum=1;
        d[1]--;
        x[1]=1;
    }
    fto(i,2,n)
    {
        if(d[1]*d[2]==0)
        {
            if(d[1]==0)
            {
                x[i]=2;
                sum+=2;
                d[2]--;
                continue;
            }
            if(d[2]==0)
            {
                x[i]=1;
                sum+=1;
                d[1]--;
                continue;
            }
        }
        else
        {
            //if(i==2) cout<<D[sum+1]<<"cc";
            if(!D[sum+1])
            {
                x[i]=1;
                sum+=1;
                d[1]--;
                continue;
            }
            else
            {
                x[i]=2;
                sum+=2;
                d[2]--;
            }
        }
    }
    fto(i,1,n)
    cout<<x[i]<<' ';
}