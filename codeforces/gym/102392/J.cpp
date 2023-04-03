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
deque<int> a[1000];
int n;
/* Variable explain:

*/
void read(int argc, char *argv[])
{
    scanf("%d", &n);
    int ls1, ls2, ls3;
    for (int i = 1; i <= (n * (n - 1)) >> 1; ++i)
    {
        scanf("%d%d%d", &ls1, &ls2, &ls3);
        a[ls1].push_back(ls3);
        a[ls2].push_back(ls3);
    }
    for (int i = 1; i <= n; ++i)
        sort(a[i].begin(), a[i].end());
    return;
}
int main(int argc, char *argv[])
{
    // freopen(".in","r",stdin);
    // freopen(".out","w",stdout);
    read(argc, argv);
    long long ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < a[i].size(); j += 2)
        {
            ans += max(a[i][j], a[i][j + 1]);
        }
    }
    printf("%lld\n", ans);
    return 0;
}