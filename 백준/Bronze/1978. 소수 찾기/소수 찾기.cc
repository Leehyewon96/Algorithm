#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

bool IsPrimeNumber(int num);

int main()
{
    int n;
    cin >> n;
    int num;
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> num;
        if (IsPrimeNumber(num))
        {
            ++cnt;
        }
    }

    cout << cnt;
    return 0;
    

}

bool IsPrimeNumber(int num)
{
    if (num == 1)
    {
        return false;
    }
    int m = num - 1;
    while (m != 1)
    {
        if (num % m == 0)
        {
            return false;
        }

        --m;
    }

    return true;
}