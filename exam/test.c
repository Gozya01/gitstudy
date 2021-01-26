#include <stdio.h>
void split(int n, int *a, int k)
{
    int i, j, flag;
    if (n > 0)
    {
        if (k == 0 || n <= a[k - 1])
            i = n;
        else
            i = a[k - 1] - 1;
        for (;i>=1;i--){
            flag = 1;
            for (j = 2; j < i - 1&&flag;j++){
                if(i%j==0||i>99)
                    flag = 0;
            }
            if(flag==1){
                a[k] = i;
                split(n - i, a, k + 1);
                break;
            }
        }
    }
    return;
}
int main(){
    int a[5];
    split(234, a, 0);
    for (int i = 0; i < 5;++i)
        printf("%d\n", a[i]);
}
