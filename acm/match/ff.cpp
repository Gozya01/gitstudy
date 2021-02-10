#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e7 + 10;
typedef long long ll;
int f[maxn];
int l, r;
void Dfs(int c1, int c2, ll sum, int base,bool fx)
{
    if (sum > r)
        return;
    f[sum]++;
    if(fx)Dfs(c1, c2, sum * base + c1, base,0);
    else Dfs(c1, c2, sum * base + c2, base,1);
}
void Work(int x)
{
    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if(i!=0)Dfs(i, j, i * x * x + j * x + i, x,0);
            
            if(j!=0)Dfs(i, j, j * x * x + i * x + j, x,1);
        }
    }
}
int main()
{
    int b1, b2;
    scanf("%d%d%d%d",&b1,&b2,&l,&r);
    for (int i = b1;i<=b2;++i)Work(i);
    int k=0;
    for (int i = l; i <= r;++i)
        k = max(k, f[i]);
    printf("%d\n", k);
    for (int i = l; i <= r;++i){
        if(k==f[i])
            printf("%d\n", i);
    }
    return 0;
}