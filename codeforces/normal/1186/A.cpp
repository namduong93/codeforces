#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int main()
{
    cin>>n>>m>>k;
    if(n>min(m,k)) cout<<"NO";
    else cout<<"YES";
}