#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
int main()
{
    double x;
    int a = 1000;
    __builtin_printf("%d\n", a);
    // __builtin_scanf("%lf", &x);
    // scanf("%lf", &x);
    int i = 0;
    double n;
    double d;
    double ans;
    i++;
    while (1)
    {
        if (i == 0)
        {
            d = x;
            n = 1;
            ans = x;
        }
        else
        {
            d = d * x * x;
            n = n * (2 * i) * (2 * i + 1);
            ans = ans + pow(-1, i) * d / n;
        }
    }
    return 0;
}