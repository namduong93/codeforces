#include<bits/stdc++.h>
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
const int N=200005;
int n;
int A[N],Max,dem;
int main()
{
   // freopen("text.txt","r",stdin);
    cin>>n;
    fto(i,1,n) cin>>A[i];
    int i=1;
    int j=n;
    while(1)
    {
        if(i>j) break;
        if(A[i]<Max&&A[j]<Max) break;
        if(A[i]<Max&&A[j]>Max)
        {
            dem++;
            Max=A[j];
            j--;
            continue;
        }
        if(A[i]>Max&&A[j]<Max)
        {
            dem++;
            Max=A[i];
            i++;
            continue;
        }
        if(A[i]>Max&&A[j]>Max)
        {
            if(A[i]<A[j])
            {
                dem++;
                Max=A[i];
                i++;
                continue;
            }
            else
            {
                dem++;
                Max=A[j];
                j--;
                continue;
            }
        }
    }
    cout<<dem<<'\n';
    i=1;
    j=n;
    Max=0;
    while(dem--)
    {
        if(A[i]<Max&&A[j]<Max) break;
        if(A[i]<Max&&A[j]>Max)
        {
            cout<<'R';
            Max=A[j];
            j--;
            continue;
        }
        if(A[i]>Max&&A[j]<Max)
        {
            cout<<'L';
            Max=A[i];
            i++;
            continue;
        }
        if(A[i]>Max&&A[j]>Max)
        {
            if(A[i]<A[j])
            {
                cout<<'L';
                Max=A[i];
                i++;
                continue;
            }
            else
            {
                cout<<'R';
                Max=A[j];
                j--;
                continue;
            }
        }
    }
}