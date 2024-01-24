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

    int M, N;
    cin >> M;
    for (int i = 0; i < M; ++i)
    {
        cin >> N;
        cout << DP(N) << '\n';
    }
    
    return 0;
}

int DP(int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return 1;
    }
    if (n == 2)
    {
        return 2;
    }
    if (n == 3)
    {
        return 4;
    }

    if (D[n] > 0)
    {
        return D[n];
    }

    
    D[n] = DP(n - 1) + DP(n - 2) + DP(n - 3);
    return D[n];
}