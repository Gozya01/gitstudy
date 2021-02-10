#include<bits/stdc++.h>
using namespace std;
const int maxn = 20 + 10;
int m;
int sum[maxn], v[maxn];
int sumx;
bool Dfs(int num,int s1,int s2,int s3,int s4){
    if(num==m+1)
        return s1 == s2 && s2 == s3 && s4 == s3;
    int Max = max(s1, max(s2, max(s3, s4)));
    int Min = min(s1, min(s2, min(s3, s4)));
    if(Max-Min>sum[m]-sum[num-1])
        return 0;
    if(s1+v[num]<=sumx&&Dfs(num + 1, s1 + v[num], s2, s3, s4))
        return 1;
    if(s2+v[num]<=sumx&&Dfs(num + 1, s1,s2 + v[num],s3,s4))
        return 1;
    if(s3+v[num]<=sumx&&Dfs(num+1,s1,s2,s3+v[num],s4))
        return 1;
    if(s4+v[num]<=sumx&&Dfs(num+1,s1,s2,s3, s4+v[num]))
        return 1;
    return 0;
}
int main(){
    int t;scanf("%d",&t);
    while(t--){
        scanf("%d", &m);
        for (int i = 1;i<=m;++i)
            scanf("%d", &v[i]),sum[i]=sum[i-1]+v[i];
        if(sum[m]%4){
             printf("no\n");
             continue;
        }
        sumx = sum[m] / 4;
        if(Dfs(1,0,0,0,0))
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}