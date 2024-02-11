#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define MOD 10007;

int D[502][502];
int DP(vector<vector<int>> vec);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N;

    vector<vector<int>> vec;
    int repeat = 1;
    for (int i = 0; i < N; ++i)
    {
        vector<int> vecInput;
        for (int j = 0; j < repeat; ++j)
        {
            cin >> M;
            vecInput.push_back(M);
        }
        vec.push_back(vecInput);
        ++repeat;
    }
    cout << DP(vec) << '\n';
    return 0;
}

int DP(vector<vector<int>> vec)
{
    D[0][0] = vec[0][0];
    //D[1][0] = vec[0][0] + vec[1][0];
    //D[1][1] = vec[0][0] + vec[1][1];

    int maxResult = D[0][0];
    for (int i = 1; i < vec.size(); ++i)
    {
        for (int j = 0; j < vec[i].size(); ++j)
        {
            if (j == 0)
            {
                D[i][j] = D[i - 1][j] + vec[i][j];
            }
            else if (j == vec[i].size() - 1)
            {
                D[i][j] = D[i - 1][j - 1] + vec[i][j];
            }
            else
            {
                D[i][j] = max(D[i - 1][j - 1], D[i - 1][j]) + vec[i][j];
            }

            if (maxResult < D[i][j])
            {
                maxResult = D[i][j];
            }
        }
    }

    return maxResult;
}