#include <bits/stdc++.h>
#define int long long
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int n,q,A[300002];
int tmp=0;
typedef pair <int,int> pii;
int a,b;
pii cc[1000002],bb[1000002];
deque <int> deq;
int gg;
main()
{
    cin>>n>>q;
    for (int i=1;i<=n;i++)
    {
        cin>>A[i];tmp=max(tmp,A[i]);
        deq.push_back(A[i]);
    }
    while (deq.front()<tmp)
    {
        a=deq.front();
        deq.pop_front();
        b=deq.front();
        deq.pop_front();
        gg++;cc[gg]={a,b};
        if (a<=b) swap(a,b);
        deq.push_front(a);deq.push_back(b);
    }
    fto(i,1,n-1)
    {
        a=deq.front();
        deq.pop_front();
        b=deq.front();
        deq.pop_front();
        bb[i]={a,b};
        if (b>=a) swap(a,b);
        deq.push_front(a);
        deq.push_back(b);
    }
    fto(i,1,q)
    {
        cin>>a;
        if (a<=gg)
        {

            cout<<cc[a].first<<' '<<cc[a].second<<'\n';
            continue;
        }
        a-=gg;
        a%=(n-1);
        if (a==0) a=n-1;
        cout<<bb[a].first<<' '<<bb[a].second<<'\n';

    }
}