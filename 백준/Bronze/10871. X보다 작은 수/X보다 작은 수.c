#include <stdio.h>
int main()
{
    int N, X;
    scanf("%d %d", &N, &X);

    int A[N];

    for(int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }

    for(int j = 0; j < N; j++)
    {
        if(A[j] < X)
        {
            printf("%d ", A[j]);
        } 
    }

    printf("\n");

    return 0;
}