#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define MOD 10007;

int D[1002];
int R_D[1002];
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
    vector<int> vecD;
   
    for (int i = 0; i < vec.size(); ++i)
    {
        D[i] = 1;
        int curMax = D[i];
        for (int j = 0; j < i; ++j)
        {
            if (vec[i] > vec[j] && curMax < D[j] + 1)
            {
                D[i] = D[j] + 1;
                curMax = D[i];
            }
        }
    }

    for (int i = vec.size() - 1; i >= 0; --i)
    {
        R_D[i] = 1;
        int curMax = R_D[i];
        for (int j = vec.size() - 1; j > i; --j)
        {
            if (vec[i] > vec[j] && curMax < R_D[j] + 1)
            {
                R_D[i] = R_D[j] + 1;
                curMax = R_D[i];
            }
        }
    }

    int maxresult = 0;
    for (int i = 0; i < vec.size(); ++i)
    {
        if (maxresult < D[i] + R_D[i] - 1)
        {
            maxresult = D[i] + R_D[i] - 1;
        }
    }
    return maxresult;
}