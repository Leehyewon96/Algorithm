#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define MOD 1000000000;

int D[100001][11];

long long DP(int N);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    cout << DP(N);
    return 0;
}

long long DP(int N)
{
    D[1][0] = 0;
    for (int i = 1; i < 10; ++i)
    {
        D[1][i] = 1;
    }

    for (int i = 2; i < N + 1; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            D[i][j] = 0;
            if (j - 1 >= 0)
            {
                D[i][j] += D[i - 1][j - 1];
            }
            if (j + 1 <= 9)
            {
                D[i][j] += D[i - 1][j + 1];
            }
            D[i][j] %= MOD;
        }
    }

    long long result = 0;
    for (int i = 0; i < 10; ++i)
    {
        result += (long long)D[N][i];
    }

    return result % MOD;
}