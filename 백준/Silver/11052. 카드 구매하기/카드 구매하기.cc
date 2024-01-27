#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int D[1000001];

int DP(vector<int> vec, int n);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> vec;
    vec.push_back(-1);
    int M, N;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> M;
        vec.push_back(M);
    }
    cout << DP(vec, N);
    return 0;
}

int DP(vector<int> vec, int n)
{
    for (int i = 1; i < vec.size(); ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            D[i] = max(vec[j] + D[i - j], D[i]);
        }
    }
    return D[n];
}