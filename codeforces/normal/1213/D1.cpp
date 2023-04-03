#include<bits/stdc++.h>
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
const int N=55;
const int oo=20;
int n,k,rs,kq=1e8;
int a[N];
priority_queue<int, vector<int> , greater<int> > heap;
int main()
{
    //freopen("test.inp","r",stdin);
    cin>>n>>k;
    fto(i,1,n) cin>>a[i];
    fto(tt,1,n)
    {
        int Pow=1;
        fto(i,0,17)
        {
            if(i!=0)
            Pow=Pow*2;
            int st=a[tt]/Pow;
            while(!heap.empty()) heap.pop();
            fto(j,1,n)
            {
                int Pow1=1;
                int ht=oo;
                fto(gg,0,17)
                {
                    if(gg!=0)
                    Pow1=Pow1*2;
                    if(a[j]/Pow1==st)
                    {
                        ht=min(ht,gg);
                        break;
                    }
                }
                if(ht!=oo)
                heap.push(ht);
            }
            rs=0;
            if(heap.size()<k) continue ;
            fto(gg,1,k)
            {
                rs+=heap.top();
                heap.pop();
            }
            kq=min(kq,rs);
        }
    }
    cout<<kq;
}