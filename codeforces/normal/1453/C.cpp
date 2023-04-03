#include<bits/stdc++.h>
#define fto(i,a,b) for(int i=a;i<=b;++i)
#define fdo(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
const int N=2005;
int Test,n;
int C[N],R[N];
int a[N][N],b[N][N];
string str;
int cc1,cc2;
int main()
{
    //freopen("test.inp","r",stdin);
    cin>>Test;
    fto(kk,1,Test)
    {
        cin>>n;
        fto(i,1,n)
        {
            cin>>str;
            fto(j,1,n)
            a[i][j]=str[j-1]-'0';
        }
        fto(gg,0,9)
        {
            fto(i,1,n) C[i]=R[i]=0;
            int rs=0;
            fto(i,1,n) fto(j,1,n)
            if(a[i][j]==gg)
            {
                if(C[j]==0) C[j]=i;
                else
                {
                    int s1=(i-C[j])*(n-j);
                    int s2=(i-C[j])*(j-1);
                    rs=max(rs,max(s1,s2));
                }
                if(R[i]==0) R[i]=j;
                else
                {
                    int s1=(j-R[i])*(n-i);
                    int s2=(j-R[i])*(i-1);
                    rs=max(rs,max(s1,s2));
                    //if(gg==0&&i==1&&j==3) cout<<R[1];
                }
            }

            cc1=cc2=N;
            fto(i,1,n) fto(j,1,n)
            if(a[i][j]==gg)
            {
                if(cc1!=N&&cc2!=N)
                {
                    rs=max(rs,(i-1)*(j-cc2));
                    rs=max(rs,(j-1)*(i-cc1));
                }
                cc1=min(cc1,i);
                cc2=min(cc2,j);
            }

            cc1=cc2=0;
            fdo(i,n,1) fdo(j,n,1)
            if(a[i][j]==gg)
            {
                if(cc1!=0&&cc2!=0)
                {
                    rs=max(rs,(n-i)*(cc2-j));
                    rs=max(rs,(n-j)*(cc1-i));
                }
                cc1=max(cc1,i);
                cc2=max(cc2,j);
            }

            fto(i,1,n) fto(j,1,n) b[i][j]=a[i][n-j+1];

            cc1=cc2=N;
            fto(i,1,n) fto(j,1,n)
            if(b[i][j]==gg)
            {
                if(cc1!=N&&cc2!=N)
                {
                    rs=max(rs,(i-1)*(j-cc2));
                    rs=max(rs,(j-1)*(i-cc1));
                }
                cc1=min(cc1,i);
                cc2=min(cc2,j);
            }

            cc1=cc2=0;
            fdo(i,n,1) fdo(j,n,1)
            if(b[i][j]==gg)
            {
                if(cc1!=0&&cc2!=0)
                {
                    rs=max(rs,(n-i)*(cc2-j));
                    rs=max(rs,(n-j)*(cc1-i));
                }
                cc1=max(cc1,i);
                cc2=max(cc2,j);
            }
            cout<<rs<<' ';
        }
        cout<<'\n';
    }
}