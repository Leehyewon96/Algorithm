#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define MOD 1000000000;

int D[204][204];
void DP(int N, int K);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;
    DP(N, K);
    return 0;
}

void DP(int N, int K)
{
    D[0][0] = 1LL;
    for (int i = 1; i <= K; ++i)
    {
        for (int j = 0; j <= N; ++j)
        {
            for (int l = 0; l <= j; ++l)
            {
                D[i][j] += D[i - 1][j - l];
                D[i][j] %= MOD;
            }
        }
    }
    
    cout << D[K][N] << '\n';
}