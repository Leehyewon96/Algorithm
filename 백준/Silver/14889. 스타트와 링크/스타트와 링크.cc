#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N = 0;
    int weights[21][21];
    int aTeamSum = 0;
    int bTeamSum = 0;
    vector<int> aVec;
    vector<int> bVec;

    int minDif = 99999999999999;

    cin >> N;

    for (int i = 0; i < N; ++i) 
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> weights[i][j];
        }
    }

    for (int i = 0; i < (1 << N); ++i)
    {
        aVec.clear();
        bVec.clear();

        for (int j = 0; j < N; ++j)
        {
            if (i & (1 << j))
            {
                aVec.push_back(j);
            }
            else
            {
                bVec.push_back(j);
            }
        }

        if (aVec.size() != N / 2)
        {
            continue;
        }

        aTeamSum = 0;
        bTeamSum = 0;
        for (int i = 0; i < N / 2; ++i)
        {
            for (int j = 0; j < N / 2; ++j)
            {
                aTeamSum += weights[aVec[i]][aVec[j]];
                bTeamSum += weights[bVec[i]][bVec[j]];
            }
        }

        int curDif = abs(aTeamSum - bTeamSum);
        minDif = min(minDif, curDif);

        
    }

    cout << minDif << '\n';
    return 0;
}