#include<bits/stdc++.h>
#define fto(i,a,b) for(int i=a;i<=b;++i)
#define fdo(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
const int N=505;
int getbit(int x,int i) {return x&(1<<i);}
int turnbit(int x,int i) { return x|(1<<i);}
int swapbit(int x,int i) {return x^(1<<i);}
int n,m;
int a[N][N];
int c[N][N];
int Trc1[N],Trc0[N];
int x;
stack<int> sta;
int main()
{
    cin>>n>>m;
    fto(i,1,n)
    fto(j,1,m)
    cin>>a[i][j];
    fto(bit,1,11)
    {
        fto(i,1,n)
        fto(j,1,m)
        if(getbit(a[i][j],bit-1)) c[i][j]=1;
        else c[i][j]=0;
        fto(i,1,n)
        Trc0[i]=Trc1[i]=-1;
        fto(g,1,m)
        if(c[1][g])
        Trc1[1]=g;
        else Trc0[1]=g;
        //if(bit==1) cout<<Trc0[1];
        fto(i,2,n)
        {
            Trc0[i]=-1;
            Trc1[i]=-1;
            if(Trc0[i-1]!=-1)
            fto(j,1,m)
            if(c[i][j]) Trc1[i]=j;
            else Trc0[i]=j;
            if(Trc1[i-1]!=-1)
            fto(j,1,m)
            if(c[i][j]) Trc0[i]=j;
            else Trc1[i]=j;
        }
        bool gg=true;
        if(Trc1[n]!=-1)
        {
            fdo(i,n,1)
            {
                if(gg)
                x=Trc1[i];
                else x=Trc0[i];
                sta.push(x);
                if(c[i][x])
                {
                    if(gg) gg=false;
                    else gg=true;
                }
                else
                {
                    if(gg) gg=true;
                    else gg=false;
                }
            }
            cout<<"TAK"<<'\n';
            while(!sta.empty())
            {
                cout<<sta.top()<<' ';
                sta.pop();
            }
            return 0;
        }
    }
    cout<<"NIE";
}