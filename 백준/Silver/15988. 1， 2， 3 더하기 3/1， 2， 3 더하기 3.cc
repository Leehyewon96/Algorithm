#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define MOD 1000000009;

long long D[1000001];
long long DP(int m);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N;
    vector<long long> vec;
    for (int i = 0; i < N; ++i)
    {
        cin >> M;
        vec.push_back(DP(M));
    }
    
    for (int i = 0; i < vec.size(); ++i)
    {
        cout << vec[i] << '\n';
    }
    
    return 0;
}

long long DP(int m)
{
    D[1] = 1;
    D[2] = 2;
    D[3] = 4;

    for (int i = 4; i <= m; ++i)
    {
        D[i] = (D[i - 1] + D[i - 2] + D[i - 3]) % MOD;
    }

    return D[m];
}