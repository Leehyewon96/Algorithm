#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define MOD 1000000000;

long long D[100001];
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
    D[1] = 1;
    D[2] = 1;
    if (D[N] > 0)
    {
        return D[N];
    }
    D[N] = DP(N - 1) + DP(N - 2);
    return D[N];
}