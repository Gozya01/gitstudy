#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
const int mod=100;
bool vis[maxn];
int main(){
	srand(time(0)); 
	int n=rand()%mod+1,m=rand()%10+1,k=rand()%mod+1;
	printf("%d %d %d\n",n,m,k);
	while(m--){
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;++i){
			int z=rand()%n+1;
			while(vis[z])z=rand()%n+1;
			vis[z]=1;
			printf("%d ",z); 
		}
		printf("\n");
	}
	return 0;
}
