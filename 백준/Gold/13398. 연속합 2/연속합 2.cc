#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define MOD 10007;

int D[100002];
int D_R[100002];
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
    D[0] = vec.front();
    for (int i = 1; i < vec.size(); ++i)
    {
        if (i == 0)
        {
            D[i] = vec[i];
        }
        else
        {
            D[i] = max(D[i - 1] + vec[i], vec[i]);
        }
    }

    for (int i = vec.size() - 1; i >= 0; --i)
    {
        if (i == vec.size() - 1)
        {
            D_R[i] = vec[i];
        }
        else
        {
            D_R[i] = max(D_R[i + 1] + vec[i], vec[i]);
        }
    }

    int maxResult = D[0];
    for (int i = 1; i < vec.size(); ++i)
    {
        maxResult = max(maxResult, D[i]);
    }

    for (int i = 1; i < vec.size() - 1; ++i)
    {
        maxResult = max(maxResult, D[i - 1] + D_R[i + 1]);
    }

    return maxResult;
}