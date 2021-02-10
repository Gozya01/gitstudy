#include<bits/stdc++.h>
int main(){
    srand(time(0));
    int t=rand()%20+1;
    printf("%d\n",t);
    while(t--){
        int n=rand()%10+2;
        printf("%d\n",n);
        for(int i=1;i<=n;++i){
            printf("%d ",rand());
        }
        puts("");
    }
    return 0;
}