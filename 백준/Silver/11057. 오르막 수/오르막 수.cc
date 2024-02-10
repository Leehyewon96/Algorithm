#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define MOD 10007;

int D[1001][10];
int DP(int num);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    cout << DP(N) << '\n';
    return 0;
}

int DP(int num)
{
    for (int i = 0; i <= 9; ++i)
    {
        D[1][i] = 1;
    }

    for (int i = 2; i <= num; ++i)
    {
        for (int j = 0; j <= 9; ++j)
        {
            for (int l = 0; l <= j; ++l)
            {
                D[i][j] += D[i - 1][l] % MOD;
            }
        }
    }

    int result = 0;
    for (int j = 0; j <= 9; ++j)
    {
        result += D[num][j] % MOD;
    }

    return result % MOD;
}