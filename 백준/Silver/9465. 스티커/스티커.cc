#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define MOD 10007;

int D[100001][4];
int DP(vector<vector<int>> vec);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N;
    int score;
    
    
    for (int i = 0; i < N; ++i)
    {
        cin >> M;
        vector<vector<int>> vec;
        vector<int> vecScore;
        for (int j = 0; j < M; ++j)
        {
            cin >> score;
            vecScore.push_back(score);
            vec.push_back(vecScore);
            vecScore.clear();
        }
        
        for (int j = 0; j < M; ++j)
        {
            cin >> score;
            vec[j].push_back(score);
        }

        cout << DP(vec) << '\n';
    }

    return 0;
}

int DP(vector<vector<int>> vec)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        D[i][0] = 0;
        D[i][1] = vec[i][0];
        D[i][2] = vec[i][1];
    }

    for (int i = 1; i < vec.size(); ++i)
    {
        D[i][0] += max(D[i - 1][0], max(D[i - 1][1], D[i - 1][2]));
        D[i][1] += max(D[i - 1][0], D[i - 1][2]);
        D[i][2] += max(D[i - 1][0], D[i - 1][1]);
    }

    return max(D[vec.size() - 1][0], max(D[vec.size() - 1][1], D[vec.size() - 1][2]));
}