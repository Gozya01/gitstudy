#include <stdio.h>
#include <stdlib.h>
#define MAXN 10
typedef float ElementType;

ElementType Median(ElementType A[], int N);
ElementType A[MAXN];
int main()
{
    int N, i;
    int a = 0xfff;
    scanf("%d", &N);
   // Median(A, N);
    for (i = 0; i < N; i++)
        scanf("%f", &A[i]);
    printf("%.2f\n", Median(A, N));
    return 0;
}
ElementType Median(ElementType A[], int N)
{
    int i = 0, j = N - 1;
    float x = A[0];
    ElementType min = 0, value = 0;
    qsort(0, N - 1, A, N);
    for (i = 0; i <= N - 1; i++)
    {
        printf("A[%d]=%.2f\n", i, A[i]);
    }
}
void Qsort1(int left, int right, int N)
{
    if (left >= right)
        return;
    float x = A[left];
    int i = left, j = right;
    printf('-');
    while (i < j)
    {
        while (i < j && A[j] >= x)
            j--;
        while (i < j && A[i] <= x)
            i++;
        if (i < j)
        {
            float num = A[i];
            A[i] = A[j];
            A[j] = num;
        }
        //printf('-');
    }
    A[left] = A[i];
    A[i] = x;
    Qsort1(left + 1, i - 1,N);
    Qsort1(i + 1, N - 1,N);
}

/*
4
1.3
-9.3
4.6
66
*/