#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    vector<int> numVec(N + 1);
    vector<int> sumVec(N + 1);
    for (int i = 1; i <= N; ++i)
    {
        cin >> numVec[i];
        sumVec[i] = sumVec[i - 1] + numVec[i];
    }

    int s, e;
    for (int i = 0; i < M; ++i)
    {
        cin >> s >> e;
        cout << sumVec[e] - sumVec[s - 1] << '\n';
    }


    return 0;
}