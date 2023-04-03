#include<bits/stdc++.h>
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
const int N=55;
int n;
char ch[N][N];
int main()
{
    cin>>n;
    fto(i,1,n)
    fto(j,1,n) cin>>ch[i][j];
    fto(i,1,n)
    {
        fto(j,1,n)
        if(ch[i][j]=='.')
        {
            ch[i][j]='#';
            if(ch[i+1][j-1]=='#'||i+1>n||j-1<1) {cout<<"NO";return 0;}
            ch[i+1][j-1]='#';
            if(ch[i+1][j]=='#'||i+1>n) {cout<<"NO";return 0;}
            ch[i+1][j]='#';
            if(ch[i+1][j+1]=='#'||i+1>n||j+1>n) {cout<<"NO";return 0;}
            ch[i+1][j+1]='#';
            if(ch[i+2][j]=='#'||i+2>n) {cout<<"NO";return 0;}
            ch[i+2][j]='#';
        }
    }
    fto(i,1,n) fto(j,1,n) if(ch[i][j]=='.') {cout<<"NO";return 0;}
    cout<<"YES";
}