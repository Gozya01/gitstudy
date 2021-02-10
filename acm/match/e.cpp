/*
合成一个樱桃的方案得分
1
0
合成一个橘子前的得分
两个樱桃合并+2
0
4
3
2
柠檬+3
0
3
5
6
7
8
9
10
11
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn =10000;
bool f[maxn][20];
int main(){
    f[0][1] = 1;
    for (int i = 1; i <= 4;++i){
        f[0][i + 1] = 1;
        for (int j = 0; j < maxn/2;++j){
            if(!f[j][i])
                continue;
            for (int k = 0; k < maxn/2;++k){
                if(!f[k][i])
                    continue;
                f[j + k+i][i + 1] = 1;
            }
        }
    }
    for (int i = 5; i <= 10;++i){
        for (int j = 0; j < maxn/2;++j){
            if(!f[j][i])
                continue;
            for (int k = 0; k < maxn/2;++k){
                if(!f[k][i])
                    continue;
                if(i!=10)f[j + k+i][i + 1] = 1;
                else
                    f[j + k + i + 100][i + 1] = 1;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < maxn;++i)if(f[i][11]==1)ans++;
    printf("%d\n", ans);
    return 0;
}
//编程题第五题中的lcm(i,j)可能超过int64范围，但是你可以认为图片内的函数不会溢出，只需要把n^2个lcm的原始的和对1e9+7取模输出即可//
//填空题4附图为示意图，最终所用到的每截木棍应为同一长度，请填写这个答案。且材料有可能出现剩余。 (广播消息，勿回^_^)//
