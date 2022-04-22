#include <stdio.h>
int main()
{
    int N, count = 0;
    scanf("%d", &N);

    int newNum = N - 1;
    int keepNum = N;

    while(N != newNum)
    { 
        int decNum = keepNum / 10;
        int digitNum = keepNum % 10;

        int midNum = decNum + digitNum;

        newNum = (digitNum * 10) + (midNum % 10);
        count++;
        keepNum = newNum;
    }

    printf("%d\n", count);

    return 0;
}