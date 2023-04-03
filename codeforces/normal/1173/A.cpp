#include<bits/stdc++.h>
using namespace std;
int x,y,z;
int main()
{
    cin>>x>>y>>z;
    if(x-y>z) {cout<<'+';return 0;}
    if(y-x>z) {cout<<'-';return 0;}
    if(x-y==0&&z==0) {cout<<0; return 0;}
    cout<<'?';
}