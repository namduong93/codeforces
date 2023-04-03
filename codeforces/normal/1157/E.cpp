///ta y mng b vo 1 multiset  m bo tnh tng dn
///vi mi a[i], ta tm s ln hn hoc bng n-a[i]
///nu c th kq l (a[i]+*it)%n, nu khng chn bmin thay *it
///u tin tm n-a[i] bi v (a[i]+n-x)%n (0<=x<=a[i]) lun <=a[i] v <a[i]+bmin
#include<bits/stdc++.h>
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
const int N=200005;
multiset<int> heaps;
multiset<int>::iterator it;
int a[N];
int n;
int main()
{
    cin>>n;
    fto(i,1,n)
    cin>>a[i];
    fto(i,1,n)
    {
        int x;
        cin>>x;
        heaps.insert(x);
    }
    fto(i,1,n)
    {
        it = heaps.lower_bound(n - a[i]);
        if(it==heaps.end()) it=heaps.begin();
        cout<<(a[i]+*it)%n<<' ';
        heaps.erase(it);
    }
}