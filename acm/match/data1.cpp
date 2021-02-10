#include<bits/stdc++.h>
using namespace std;
const int mod = 1000;
int main(){
    srand(time(0));
    int n = rand() % mod + 1;
    printf("%d\n",n);
    for (int i = 1; i <= n;++i){
        printf("%d %d\n", rand()%mod+1, rand()%mod+1);
    }
    return 0;
}