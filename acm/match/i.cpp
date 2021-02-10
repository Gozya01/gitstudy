#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
void Work(int);
int n, m, k;
int a[maxn], b[maxn];
int opt[15][maxn];
void Work(int id){
    for (int i = 1; i <= n;++i){
        b[i] = a[opt[id][i]];
    }
    for (int i = 1; i <= n;++i)
        a[i] = b[i];
}
void Print(){
    for (int i = 1; i <= n;++i){
        if(i!=n)
            printf("%d ", a[i]);
        else
            printf("%d\n", a[i]);
    }
}
int main(){
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; ++i)
        a[i] = i;
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            scanf("%d", &opt[i][j]);
        }
    }
    int id = 1;
    while(k--){
        Work(id);
        id++;
        if(id==m+1)
            id = 1;
    }
    for (int i = 1; i <= n;++i){
        if(i!=n)
            printf("%d ", a[i]);
        else
            printf("%d\n", a[i]);
    }
    return 0;
}
/*
6 5 7
5 2 6 3 1 4 
2 4 5 1 3 6 
4 2 3 1 5 6 
6 5 1 3 4 2 
2 1 5 4 6 3
*/
