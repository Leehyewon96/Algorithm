#include <iostream>

using namespace std;

int Ari(int num);// 등차수열인지 확인하는 함수

int main()
{
    int num;
    int arr[1001] = {0, };
    int count = 0;
    cin >> num;

    for(int i = 1; i <= num; i++)
    {
        if(Ari(i) == 1)
        {
            count++;
        }
    }
    
    printf("%d", count);

    return 0;
}

int Ari(int num)// 등차수열인지 확인하는 함수
{
    int newnum, cnt = 0;
    newnum = num / 10;
    int cd = newnum % 10 - num % 10;
    int result;
    while(newnum > 0)
    {
        if(cd != newnum%10 - num%10)
        {
            cnt++;
        }
        newnum /= 10;
        num /= 10;
    }
    if(cnt == 0)
    {
        result = 1;
    }
    else
    {
        result = 2;
    }

    return result;
}
