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
char s[1000010];
int n;
int num[300], diff;
deque<int> q;
/* Variable explain:

*/
void read(int argc, char *argv[])
{
    scanf("%s", s);
    n = strlen(s);
    sort(s, s + n);
    return;
}
int main(int argc, char *argv[])
{
    // freopen(".in","r",stdin);
    // freopen(".out","w",stdout);
    read(argc, argv);
    for (int i = 0; i < n; ++i)
        num[s[i]]++;
    int flag = 0;
    for (int i = 'a'; i <= 'z'; ++i)
    {
        diff += num[i] != 0;
        if (num[i] > n >> 1)
            flag = i;
    }
    if (flag)
    {
        if (num[flag] >= n - 2 && diff < 3)
        {
            puts("NO");
            return 0;
        }
        for (int i = 0; i < n; ++i)
        {
            if (s[i] != flag)
                q.push_back(s[i]);
        }
        sort(q.begin(), q.end());
        int T = 0;
        for (int i = 0; i < (n >> 1) - 1; ++i)
        {
            num[flag]--;
            s[T++] = flag;
        }
        s[T++] = q[0];
        q.pop_front();

        while (num[flag]--)
        {

            s[T++] = flag;
        }
        s[T++] = q.back();
        q.pop_back();
        while (q.size())
        {
            s[T++] = q[0];
            q.pop_front();
        }
    }
    printf("YES\n%s\n", s);
    return 0;
}