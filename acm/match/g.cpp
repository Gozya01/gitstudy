#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
struct Node{
    int x, y;
    bool operator <(const Node &a)const {
        if(x==a.x)return y<a.y;
        return x < a.x;
    }
}a[maxn];
int n;
vector<Node> tmp;
bool Check(int id){
    for (int i = 1; i <= n;++i){
        if(id==i)continue;
        if(a[i].x>=a[id].x&&a[i].y>=a[id].y)
            return 0;
    }
    return 1;
}
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n;++i){
       scanf("%d%d", &a[i].x, &a[i].y);
    }
    sort(a + 1, a + 1 + n);
    int ans = 0;
    for (int i = 1; i <= n;++i){
        if(Check(i))
            ans++,tmp.push_back(a[i]);
    }
    printf("%d\n", ans);
    for (int i = 0; i < tmp.size();++i){
        printf("%d %d\n", tmp[i].x, tmp[i].y);
    }
    return 0;
}