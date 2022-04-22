#include <stdio.h>

int main()
{
    int A, B;
    int C;

    scanf("%d %d", &A, &B);
    scanf("%d", &C);
    
    B += C;

    if (B < 60)
    {
        printf("%d %d", A, B);
    }
    else 
    {
        A += B / 60;
        B %= 60;

        if(A <= 23)
        {
            printf("%d %d", A, B);
        }
        else
        {
            A -= 24;
            printf("%d %d", A, B);
        }
    }
    

    return 0;
}