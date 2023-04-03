#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
vector<int>cc;
bool solve()
{
    if(!cc.size())
	{
		cout<<n;
		return true;
	}
	if(cc.size()==1)
	{
		cout<<cc[0];
		return true;
	}
	return false;
}
bool check(int i)
{
    if(cc[i]%cc[i-1]) return true;
    return false;
}
void read(int &v)
{
    char c; do{c=getchar();} while(!isdigit(c));
    v=c-'0'; while(isdigit(c=getchar())) v=v*10+c-'0';
}
main()
{
	read(n);
	for(int i=2; i<=sqrt(n); i++)
    if(n%i==0)
    {
        cc.push_back(i);
        if(i*i!=n) cc.push_back(n/i);
    }
    if(solve()) return 0;
	sort(cc.begin(), cc.end());

	for(int i=1; i<cc.size(); i++)
	{
		if(check(i))
		{
			cout<<1;
			return 0;
		}
	}
	cout<<cc[0];
}