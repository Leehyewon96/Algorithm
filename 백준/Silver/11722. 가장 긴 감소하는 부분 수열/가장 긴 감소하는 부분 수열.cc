#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define MOD 10007;

int D[1002];
int DP(vector<int> vec);

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

int DP(vector<int> vec)
{
    int maxResult = 1;
    for (int i = 0; i < vec.size(); ++i)
    {
        D[i] = 1;
        int curmax = 1;
        for (int j = 0; j < i; ++j)
        {
            if (vec[i] < vec[j] && 1 + D[j] > curmax)
            {
                D[i] = D[j] + 1;
                curmax = D[i];
            }
        }

        maxResult = max(maxResult, curmax);
    }

    return maxResult;
}