#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
struct Node{
    int x, y;
    int id;
    bool operator <(const Node &a)const {
        if(x==a.x)return y<a.y;
        return x < a.x;
    }
    bool operator ==(const Node &a)const {
        return x == a.x && y == a.y;
    }
}a[maxn];
struct node{
    int l, r, max;
} b[maxn * 4];
void Build(int rt, int l, int r);
void Update(int rt, int pos, int x);
int n;
vector<Node> tmp;
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n;++i){
       scanf("%d%d", &a[i].x, &a[i].y);
       a[i].id = 0;
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n;++i){
        a[i].id = i;
    }
   // printf("%d %d++\n", a[n].x, a[n].y);
  //  printf("%d %d++\n", a[n - 1].x, a[n - 1].y);
    Build(1,1,n);
    int ans = 0;
    for (int i = n; i >= 1;--i){
        if(b[1].max<a[i].y){
            if((a[i].x==a[i-1].x&&a[i].y==a[i-1].y)||(a[i].x==a[i+1].x&&a[i].y==a[i+1].y)){
                Update(1, i, a[i].y);
                continue;
            }
            ans++;
            tmp.push_back(a[i]);
        }
        Update(1, i, a[i].y);
    }
    printf("%d\n", ans);
    for (int i = tmp.size() - 1;i>=0;--i){
        printf("%d %d\n", tmp[i].x, tmp[i].y);
    }
    return 0;
}
void Build(int rt,int l,int r){
    b[rt].l = l;
    b[rt].r = r  ;
    if(l==r)
        return;
    int mid = (l + r) >> 1;
    Build(rt<<1,l,mid);
    Build(rt << 1 | 1, mid + 1, r);
}
void Update(int rt,int pos,int val){
    if(b[rt].l>pos||b[rt].r<pos)
        return;
    if(b[rt].l==b[rt].r){
        b[rt].max = val;
        return;
    }
    Update(rt<<1,pos,val);
    Update(rt << 1 | 1, pos, val);
    b[rt].max = max(b[rt << 1].max, b[rt << 1 | 1].max);
}