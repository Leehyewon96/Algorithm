#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int D[1000001];

int DP(int n);


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    cout << DP(N);
    return 0;
}

int DP(int n)
{
    if (n == 1)
    {
        return 1;
    }
    if (n == 2)
    {
        return 3;
    }

    if (D[n] > 0)
    {
        return D[n];
    }

    D[n] = (DP(n - 1) + 2 * DP(n - 2)) % 10007;
    return D[n];
}