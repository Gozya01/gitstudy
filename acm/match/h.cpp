#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
const int maxn=5000+10;
const int mod = 1e9 + 7;
vector<int> edge[maxn];
vector<int> cost[maxn];
ll a[maxn], b[maxn];
ll cnt[maxn], cntx[maxn];
int in[maxn];
int inx[maxn];
int n;
void Topsort(ll *, int *,ll*);
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
    for(int i=1;i<=n;++i)scanf("%lld",&b[i]);
    for(int i=1;i<=n;++i){
        int k;scanf("%d",&k);
        for(int j=1;j<=k;++j){
            int x,y;
            scanf("%d%d", &x, &y);
            in[x]++;
            inx[x]++;
            edge[i].push_back(x);
            cost[i].push_back(y);
        }
    }
    Topsort(a,in,cnt);
    Topsort(b,inx,cntx);
    for(int i=1;i<=n;++i){
        if(edge[i].size()==0)printf("%d ",0);
        else {
            int k = (a[i] - b[i]+mod)%mod;
            k = max(k, 0);
            printf("%d ", k);
        }
    }
    printf("\n");
    return 0;
}
void Topsort(ll *c,int *d,ll *e){
    queue<int> q;
    for(int i=1;i<=n;++i){
        if(d[i]==0)q.push(i);
    }
    while(!q.empty()){
        int t=q.front();q.pop();
        for(int i=0;i<edge[t].size();++i){
            int y = edge[t][i];
            e[y] += c[t] * cost[t][i] /mod;
            e[y] += (c[y] + c[t] * cost[t][i] % mod) / mod;
            c[y] = (c[y] + c[t] * cost[t][i] % mod) % mod;
            d[y]--;if(!d[y])
                q.push(y);
        }
        if(edge[t].size()!=0)
            c[t] = 0;
    }
}