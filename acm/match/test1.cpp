#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=1000;
    while(n--){
        system("data1>data1.out");
        system("g <data1.out>g.out");
        system("gg <data1.out>gg.out");
        if(system("fc g.out gg.out"))
            break;
    }
    return 0;
}