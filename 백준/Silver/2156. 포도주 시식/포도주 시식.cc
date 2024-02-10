#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define MOD 10007;

int D[10001];
long long DP(vector<int> vec);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N;

    vector<int> vec;
    for (int i = 0; i < N; ++i)
    {
        cin >> M;
        vec.push_back(M);
    }
    cout << DP(vec) << '\n';
    return 0;
}

long long DP(vector<int> vec)
{
    D[0] = 0;
    D[1] = vec[0];
    D[2] = vec[0] + vec[1];
    for (int i = 3; i <= vec.size(); ++i)
    {
        D[i] = max(D[i - 3] + vec[i - 2] + vec[i - 1], max(D[i -2] + vec[i-1], D[i - 1]));
    }

    return D[vec.size()];
}