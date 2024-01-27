#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define MOD 1000000000;

long long D[100001][3];
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
    D[1][1] = 1;
    for (int i = 2; i <= N; ++i)
    {
        for (int j = 0; j <= 1; ++j)
        {
            if (j == 0)
            {
                D[i][j] = D[i - 1][0] + D[i - 1][1];
            }
            else
            {
                D[i][j] = D[i - 1][0];
            }
        }
    }

    return (long long)D[N][0] + D[N][1];
}