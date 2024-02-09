#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define MOD 1000000000;

int D[100000];
int DP(vector<int> vec);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    int M;
    vector<int> vec;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> M;
        vec.push_back(M);
    }
    cout << DP(vec) << '\n';
    return 0;
}

int DP(vector<int> vec)
{
    D[0] = vec.front();
    int maxSum = D[0];
    for (int i = 1; i < vec.size(); ++i)
    {
        D[i] = max(vec[i] + D[i - 1], vec[i]);
        maxSum = max(D[i], maxSum);
    }

    return maxSum;
}