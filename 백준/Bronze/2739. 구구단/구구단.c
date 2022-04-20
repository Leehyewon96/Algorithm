#include <stdio.h>

int main()
{
    int N, mul;

    scanf("%d", &N);

    for(int i = 1; i <= 9; i++)
    {
         mul = N * i;
         printf("%d * %d = %d\n", N, i, mul);
    }

    return 0;
}