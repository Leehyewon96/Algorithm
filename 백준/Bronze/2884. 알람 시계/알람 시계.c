#include <stdio.h>

int main()
{
    int H, M, h, m;

    scanf("%d %d", &H, &M);

    
    if(M < 45)
    {
        if(H != 0)
        {
            H -= 1;
            M += 15;
            printf("%d %d", H, M);
        }
        else
        {
            H += 23;
            M += 15;
            printf("%d %d", H, M);
        }
    }
    else if(M >= 45)
    {
        M -= 45;
        printf("%d %d", H, M);
    }
    


    return 0;
}