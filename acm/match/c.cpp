#include<bits/stdc++.h>
using namespace std;
int ans = 500;
char s[500];
int a[500];
int start;
void Flip(int);
void Work(int);
int main(){
    scanf("%s", s + 1);
    for (int i = 1; i <= 100;++i){
        Work(i);
    }
    printf("%d\n", ans);
    return 0;
}
void Flip(int x){
    a[x]=!a[x];
    a[x + 1] = !a[x + 1];
    if(x==start){
        a[start + 99] = !a[start + 99];
    }
    else
        a[x - 1] = !a[x - 1];
}
void Work(int sx){
    start = sx;
    for (int i = sx; i <= sx + 100-1;++i){
        a[i] = s[i - sx + 1] - '0';
    }
    int cnt = 0;
    for (int i = sx;i<=sx + 100-2;++i){
        if(a[i]!=1)
            Flip(i),cnt++;
    }
    if(a[sx+99]==1)ans=min(ans,cnt),printf("%d\n",sx);
} 