#include <bits/stdc++.h>
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
const int N=1000005;
string A,B;
int sA[N],sB[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>A>>B;
	int m=A.size();int n=B.size();
	A=' '+A;B=' '+B;
    memset(sA,0,sizeof(sA));
    memset(sB,0,sizeof(sB));
	fto(i,1,m)
        sA[i]=sA[i-1]+(A[i]=='1');
	fto(i,1,n)
        sB[i]=sB[i-1]+(B[i]=='1');

	int res=0;
	fto(i,n,m)
    {
		int cur=sA[i]-sA[i-n]+sB[n];
		if (cur%2==0) ++res;
	}
	cout<<res;
}