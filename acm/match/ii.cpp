#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n, m, k;
struct Martix{
    int a[maxn];
    void Zero(){memset(a, 0, sizeof(a));}
    void One() { 
        for (int i = 1; i <= n;++i)
            a[i] = i;
    }
    void Print(){
    	for(int i=1;i<=n;++i)printf("%d ",a[i]);
    	printf("\n");
	}
    Martix operator* (const Martix &b)const{
        Martix c;
        c.Zero();
        for (int i = 1; i <= n;++i)
            c.a[i] = a[b.a[i]];
        return c;
    }
};
Martix M, Mm;
int a[maxn];
int b[maxn]; 
int opt[15][maxn];
void Work(int id)
{
    for (int i = 1; i <= n; ++i)
    {
        b[i] = a[opt[id][i]];
    }
    for (int i = 1; i <= n; ++i)
        a[i] = b[i];
}
void Read(int &x)
{
    char ch = getchar();
    while (ch < '0' || ch > '9')
        ch = getchar();
    x = 0;
    while (ch >= '0' && ch <= '9')
        x = x * 10 + ch - 48, ch = getchar();
}
Martix Pow(Martix &a,int z){
    Martix ans;ans.One();
    while(z){
        if(z&1)
            ans = ans * a;
        a = a * a;
        z >>= 1;
    }
   // ans.Print();
    return ans;
}
int main()
{
    scanf("%d%d%d", &n, &m, &k);
    
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            Read(opt[i][j]);
        }
    }
    
    int kk = m-1;
    int id = 2;
    for (int i = 1; i <= n; ++i)
        a[i] = opt[1][i];
    while(kk--){
        Work(id);
        id++;
    }
    for (int i = 1; i <= n;++i)
        M.a[i] = a[i];
    int z = k / m;
    Martix c=Pow(M,z);
    kk = k % m;
    if(kk!=0){
        id = 2;
        kk--;
        for (int i = 1; i <= n; ++i)
        a[i] = opt[1][i];
        while(kk--){
            Work(id);
            id++;
        }
        for (int i = 1; i <= n;++i)
            Mm.a[i] = a[i];
    }
    else
        Mm.One();
    Martix t;
    t.One();
    Martix ans = t * c * Mm;
    for (int i = 1; i <= n;++i){
        if(i!=n)
            printf("%d ", ans.a[i]);
        else
            printf("%d\n", ans.a[i]);
    }
    return 0;
}
