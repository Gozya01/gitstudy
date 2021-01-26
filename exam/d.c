#include <stdio.h>
#define maxn 500 + 10
char s[maxn][maxn];
int main()
{
    char ch;
    int n;
    scanf(" %c%d", &ch, &n);
    if (!((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')))
    {
        printf("Wrong! Please enter an English letter.\n");
        return 0;
    }
    if (n % 2 == 0)
    {
        printf("Wrong! Please enter an odd number.\n");
        return 0;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if(i==j||i+j==n+1)
                s[i][j] = ' ';
            else  s[i][j] = ch;
            printf("%c ", s[i][j]);
        }
        printf("\n");
    }
    return 0;
}