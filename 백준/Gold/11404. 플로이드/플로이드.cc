#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

#define INF 10000001

int cost[101][101];

int main(void) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int V, E;
    cin >> V >> E;

    for (int i = 1; i <= V; ++i)
    {
        for (int j = 1; j <= V; ++j)
        {
            if (i == j)
            {
                cost[i][j] = 0;
            }
            else
            {
                cost[i][j] = INF;
            }
            
        }
    }

    int s, e, w;
    for (int i = 0; i < E; ++i)
    {
        cin >> s >> e >> w;
        cost[s][e] = min(cost[s][e], w);
    }

    for (int k = 1; k <= V; ++k)
    {
        for (int i = 1; i <= V; ++i)
        {
            for (int j = 1; j <= V; ++j)
            {
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }

    for (int i = 1; i <= V; ++i)
    {
        for (int j = 1; j <= V; ++j)
        {
            if (cost[i][j] == INF)
            {
                cout << 0 << ' ';
            }
            else
            {
                cout << cost[i][j] << ' ';
            }
        }

        cout << '\n';
    }

    return 0;
}