#include <stdio.h>
#define min(a, b) (((a) > (b)) ? (b) : (a))

void input(void); 
int GCD(int a, int b); 
int LCM(int a, int b); 
int MulGCD(int a[]); 
int MulLCM(int b[]); 
void betDM(int a, int b);

int main()
{
    input();
    
    return 0;
}

void input(void)
{
    int n, m;
    scanf("%d %d", &n, &m);

    int a[n];
    int b[m];
    
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < m; i++)
    {
        scanf("%d", &b[i]);
    }
    
    betDM(MulLCM(a), MulGCD(b));
}

int GCD(int a, int b)
{
    int num = 1; 
    int maxNum; 
    int n = min(a, b); 
    while(num <= n)
    {
        if(a % num == 0 && b % num == 0)
        {
            maxNum = num;
        }
        num++;
    }
    return maxNum;
}

int LCM(int a, int b)
{
    int num1 = a / GCD(a, b);
    int num2 = b / GCD(a, b);
    int minNum = num1 * num2 * GCD(a, b); 
    
    return minNum;
}

int MulGCD(int a[])
{
    int size = sizeof(a) / sizeof(a[0]);
    int temp = GCD(a[0], a[1]);
    int res = temp;
    int i = 2;
    while(i < size)
    {
        res = GCD(temp, *(a + i));
        temp = res;
        i++;
    }
    return res;
}

int MulLCM(int b[])
{
    int size = sizeof(b) / sizeof(b[0]);
    int temp = LCM(b[0], b[1]);
    int res = temp;
    int i = 2;
    while(i < size)
    {
        res = LCM(temp, *(b + i));
        temp = res;
        i++;
    }
    return res;
}

void betDM(int a, int b)
{
    int cnt = 0;
    int i = 1;
    
    while(a * i <= b)
    {
        if(b % (a * i) == 0)
        {
            cnt++;
        }
        i++;
    }
    
    printf("%d\n", cnt);
}
