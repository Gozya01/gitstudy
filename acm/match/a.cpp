#include<bits/stdc++.h>
using namespace std;
bool isPrime(int x){
    int ans = 0;
    while(x){
        ans += x % 10;
        x /= 10;
    }
    if(ans==1)
        return 0;
    for (int i = 2; i * i <= ans;++i){
        if(ans%i==0)
            return 0;
    }
    return 1;
}
int main(){
    int cnt = 0;
    for (int i = 2; i <= 8080;i+=2){
        if(isPrime(i+i+1))
            cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}