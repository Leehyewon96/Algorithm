#include <stdio.h>

int main()
{
    int A, B;
    //printf("A, B 입력\n");

    scanf("%d %d", &A, &B);

    if(A > B)
    {
        printf(">\n");
    }
    else if(A < B)
    {
        printf("<\n");
    }
    else
    {
        printf("==\n");
    }

    return 0;

}