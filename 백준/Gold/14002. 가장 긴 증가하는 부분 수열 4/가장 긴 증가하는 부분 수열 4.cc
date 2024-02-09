#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define MOD 1000000000;

int D[100001];
vector<int> DP(vector<int> vec);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    vector<int> vec;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> M;
        vec.push_back(M);
    }

    vector<int> result = DP(vec);
    cout << result.size() << '\n';
    for(int i = result.size() - 1; i >= 0; --i)
    {
        cout << result.back() << ' ';
        result.pop_back();
    }
    cout << '\n';
    return 0;
}

vector<int> DP(vector<int> vec)
{
    int max = 0;
    vector<int> maxVec;
    vector<int> tempVec;
    vector<vector<int>> resultVec;
    for (int i = 0; i < vec.size(); ++i)
    {
        D[i] = 1;
        resultVec.push_back(tempVec);
        resultVec[i].push_back(vec[i]);
        for (int j = i - 1; j >= 0; --j)
        {
            if (vec[j] < vec[i] && D[i] < D[j] + 1 && resultVec[i].size() < resultVec[j].size() + 1)
            {
                resultVec[i].clear();
                resultVec[i].push_back(vec[i]);
                for (int k = 0; k < resultVec[j].size(); ++k)
                {
                    resultVec[i].push_back(resultVec[j][k]);
                }
                D[i] = D[j] + 1;
            }
        }

        if (max < D[i])
        {
            max = D[i];
            maxVec.clear();
            maxVec = resultVec[i];
        }
    }

    return maxVec;
}