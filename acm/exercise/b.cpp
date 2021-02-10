#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 1e6 + 10;
char s1[maxn], s[maxn];
int N[maxn];
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        memset(s, 0, sizeof(s));
        memset(s1, 0, sizeof(s1));
        memset(N, 0, sizeof(N));
        scanf("%s", s + 1);
        scanf("%s", s1 + 1);
        int n = strlen(s + 1);
        int m = strlen(s1 + 1);
        int j = 0;
        for (int i = 2; i <= n; ++i)
        {
            while (j > 0 && s[j + 1] != s[i])
                j = N[j];
            if (s[i] == s[j + 1])
                j++;
            N[i] = j;
        }
        j = 0;
        int ans = 0;
        for (int i = 1; i <= m; ++i)
        {
            while (j > 0 && (j == n || s[j + 1] != s1[i]))
                j = N[j];
            if (s1[i] == s[j + 1])
                j++;
            if (j == n)
                ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
/*
abacbabab
aba
*/