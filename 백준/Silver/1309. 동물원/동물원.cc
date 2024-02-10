#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define MOD 9901;

int D[1000001][4];
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
    D[1][0] = 1;
    D[1][1] = 1;
    D[1][2] = 1;
    for (int i = 2; i <= num; ++i)
    {
        D[i][0] = (D[i - 1][0] + D[i - 1][1] + D[i - 1][2]) % MOD;
        D[i][1] = (D[i - 1][0] + D[i - 1][2]) % MOD;
        D[i][2] = (D[i - 1][0] + D[i - 1][1]) % MOD;
    }

    return (D[num][0] + D[num][1] + D[num][2]) % MOD;
}