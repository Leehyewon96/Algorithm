#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

void PrintPrimeNumber(int m, int n);

int main()
{
    int m, n;
    cin >> m >> n;

    PrintPrimeNumber(m, n);
    return 0;
    

}

void PrintPrimeNumber(int m, int n)
{
    vector<int> v;
    vector<bool> checkVec;
    for (int i = 2; i <= n; ++i)
    {
        checkVec.push_back(false);
    }

    for (int i = 0; i < checkVec.size(); ++i)
    {
        int temp = i + 2;
        if (!checkVec[i])
        {
            for (int j = temp * 2; j <= n; j += temp)
            {
                checkVec[j - 2] = true;
            }
        }
    }

    for (int i = 0; i < checkVec.size(); ++i)
    {
        if(!checkVec[i] && i + 2 >= m)
        {
            cout << i + 2 << '\n';
        }
    }
}