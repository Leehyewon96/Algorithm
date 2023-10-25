#include <iostream>
#include <vector>

using namespace std;

int BruteForce(int N);

int main()
{
    int N;
    cin >> N;

    cout << BruteForce(N);
}

int BruteForce(int N)
{
    int min = N;
    int curNum = N;
    int temp = N;
    int cur = 0;

    while (curNum != 0)
    {
        temp = curNum;
        cur += curNum;
        
        while (temp != 0)
        {
            cur += temp % 10;
            temp /= 10;
        }

        if (cur == N)
        {
            if (curNum < min)
            {
                min = curNum;
            }
        }
        
        curNum--;
        cur = 0;

        
    }

    if (min == N)
    {
        return 0;
    }
    return min;
}