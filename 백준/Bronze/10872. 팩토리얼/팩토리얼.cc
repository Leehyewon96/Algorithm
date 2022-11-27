#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*Q1 p206*/
int rec_func(int N);

int main()
{
    int N, res;
    scanf("%d", &N);

    if (N == 0)
    {
        printf("1");
    }
    else
    {
        res = rec_func(N);
        printf("%d", res);
    }
    
    return 0; 
}

int rec_func(int N)
{
    int sum = N;
    N--;
    if (N > 0)
    {
        sum *= rec_func(N);
    }
    return sum;
}
