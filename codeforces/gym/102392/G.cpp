#define _CRT_SECURE_NO_DEPRECATE
/************************
 *2022 01
 *
 *
 *
 *
 *
 ************************/
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <queue>
// #include <sys/wait.h>
// #include <sys/types.h>
// #include <unistd.h>
using namespace std;
int n, m, h;
bool a[110][110], b[110][110];
int dic[110][110][110];
bool use[1000010];
struct A
{
    int a, b, c;
    A(int a = 0, int b = 0, int c = 0) : a(a), b(b), c(c) {}
    bool operator<(const A &x) const
    {
        return a == x.a ? b == x.b ? c < x.c : b < x.b : a < x.a;
    }
};
deque<A> maxa, lsa, mina;
/* Variable explain:

*/
void read(int argc, char *argv[])
{
    scanf("%d%d%d", &n, &m, &h);
    char s[200];
    for (int i = 1; i <= n; ++i)
    {
        scanf("%s", s + 1);
        for (int j = 1; j <= m; ++j)
            a[i][j] = s[j] == '1';
    }
    for (int i = 1; i <= n; ++i)
    {
        scanf("%s", s + 1);
        for (int j = 1; j <= h; ++j)
            b[i][j] = s[j] == '1';
    }
    return;
}
bool solve()
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            for (int k = 1; k <= h; ++k)
                dic[i][j][k] = -1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (a[i][j])
                continue;
            for (int k = 1; k <= h; ++k)
                dic[i][j][k] = 0;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int k = 1; k <= h; ++k)
        {
            if (b[i][k])
                continue;
            for (int j = 1; j <= m; ++j)
                dic[i][j][k] = 0;
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (a[i][j])
            {
                int flag = 0;
                for (int k = 1; k <= h; ++k)
                    if (dic[i][j][k])
                        flag = 1;
                if (flag == 0)
                    return false;
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int k = 1; k <= h; ++k)
        {
            if (b[i][k])
            {

                int flag = 0;
                for (int j = 1; j <= m; ++j)
                    if (dic[i][j][k])
                        flag = 1;
                if (flag == 0)
                    return false;
            }
        }
    }

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            for (int k = 1; k <= h; ++k)
            {
                if (dic[i][j][k])
                {
                    maxa.push_back(A(i, j, k));
                }
            }
    sort(maxa.begin(), maxa.end());
    printf("%d\n", (int)maxa.size());
    for (auto x : maxa)
    {
        printf("%d %d %d\n", x.a - 1, x.b - 1, x.c - 1);
    }

    for (int i = maxa.size() - 1; i >= 0; --i)
    {
        if (a[maxa[i].a][maxa[i].b] && b[maxa[i].a][maxa[i].c])
        {
            use[i] = 1;
            a[maxa[i].a][maxa[i].b] = 0;
            b[maxa[i].a][maxa[i].c] = 0;
        }
    }

    for (int i = 0; i < maxa.size(); ++i)
    {
        if (a[maxa[i].a][maxa[i].b] || b[maxa[i].a][maxa[i].c])
        {
            use[i] = 1;
            a[maxa[i].a][maxa[i].b] = 0;
            b[maxa[i].a][maxa[i].c] = 0;
        }
        if (use[i])
            mina.push_back(maxa[i]);
    }
    printf("%d\n", (int)mina.size());
    for (auto x : mina)
    {
        printf("%d %d %d\n", x.a - 1, x.b - 1, x.c - 1);
    }
    // for (int i = 1; i <= n; ++i)
    // {
    //     for (int j = 1; j <= m; ++j)
    //     {
    //         if (!a[i][j])
    //             continue;
    //         for (int k = 1; k <= h; ++k)
    //             dic[i][j][k] = 1;
    //     }
    // }

    // for (int i = 1; i <= n; ++i)
    // {
    //     for (int k = 1; k <= h; ++k)
    //     {
    //         if (!b[i][k])
    //             continue;
    //         for (int j = 1; j <= m; ++j)
    //             dic[i][j][k] = 0;
    //     }
    // }
    return true;
}
int main(int argc, char *argv[])
{
    // freopen(".in","r",stdin);
    // freopen(".out","w",stdout);
    read(argc, argv);
    if (!solve())
        puts("-1");
    return 0;
}