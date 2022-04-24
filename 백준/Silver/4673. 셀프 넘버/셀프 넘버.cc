#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int d(int n); //함수 선언

int main()
{ 
    int newArray[10001] = {0,};
    int temp;
    for(int i = 0; i < 10001; i++) //1부터 10000까지 셀프넘버인지 검사
    {
        temp = d(i);
        if(temp < 10001)
        {
            newArray[temp] = 1;
        }
    }
    for(int i = 0; i < 10001; i++)
    {
        if(newArray[i] != 1)
        {
            cout << i << "\n";
        }
    }

    return 0;
}

int d(int n)
{
    int result = n;
    while(n > 0)
    {
        result += n % 10;
        n = n / 10;
    }
    return result;
}