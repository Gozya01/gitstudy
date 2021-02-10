#include<windows.h>
#include<cstdio>
int main(){
    int t=1000;
    while(t--){
        system("data>data.in");
        system("a<data.in>a.out");
        printf("%d\n",t);
    }
    return 0;
}