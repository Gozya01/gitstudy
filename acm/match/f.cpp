#include<bits/stdc++.h>
using namespace std;
const int maxn = 100 + 10;
int a[maxn];
int f[maxn * maxn * maxn * 10];
bool Check(int x, int base);
int main(){
    int b1, b2;
    scanf("%d%d", &b1, &b2);
    int l,r;
    scanf("%d%d", &l, &r);
    int k = 0;
    for (int i = l; i <= r; i++){
        for (int j = b1; j <= b2;++j){
            if(Check(i,j))
                f[i]++;
        }
        k = max(k, f[i]);
    }
    printf("%d\n", k);
    for (int i = l; i <= r;++i){
        if(f[i]==k)
            printf("%d\n", i);
    }
    return 0;
}
bool Check(int x,int base){
    int tot=0;
    while(x){
        a[++tot] = x % base;
        x /= base;
    }
    if(tot<=2)
        return 0;
    int k1 = a[1], k2 = a[2];
    if(k1==k2)
        return 0;
    for (int i = 3; i <= tot;++i){
        if(i&1&&a[i]!=k1)
            return 0;
        if(i%2==0&&a[i]!=k2)
            return 0;
    }
    return 1;
    /* bool fx = 0;
    for (int i = 1; i <= tot - 2;++i){
        if(a[i]==a[i+2]&&a[i]!=a[i+1]){
            fx = 1;
        }
    }
    if(fx){
        for (int i = 1; i <= tot;++i)
            printf("%d ", a[i]);
        printf("\n");
        return 1;
    }*/
    return 0;
}