#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define MOD 1000000009;

int D[10001][4];
int DP(vector<vector<int>> vecRGB);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    int M;
    vector<vector<int>> vecRGB;
    for (int i = 0; i < N; ++i)
    {
        vector<int> vec;
        for (int j = 0; j < 3; ++j)
        {
            cin >> M;
            vec.push_back(M);
        }
        vecRGB.push_back(vec);
    }
    cout << DP(vecRGB) << '\n';
    return 0;
}

int DP(vector<vector<int>> vecRGB)
{
    for (int i = 0; i < vecRGB.size(); ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            D[i+1][j] = vecRGB[i][j];
        }
    }

    for (int i = 1; i <= vecRGB.size(); ++i)
    {
        D[i][0] += min(D[i - 1][1], D[i - 1][2]);
        D[i][1] += min(D[i - 1][0], D[i - 1][2]);
        D[i][2] += min(D[i - 1][0], D[i - 1][1]);
    }

    return min(D[vecRGB.size()][0], min(D[vecRGB.size()][1], D[vecRGB.size()][2]));
}