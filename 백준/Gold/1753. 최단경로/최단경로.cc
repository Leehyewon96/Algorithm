#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
#define INF INT_MAX

int main(void) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int V, E;
    cin >> V >> E;

    int start;
    cin >> start;

    int s, e, w;
    vector<vector<pair<int, int>>> vec(V + 1, vector<pair<int, int>>(0));
    vector<int> costVec(V + 1, INF);
    for (int i = 0; i < E; ++i)
    {
        cin >> s >> e >> w;
        vec[s].emplace_back(e, w);
    }


    priority_queue<pair<int, int>> pq;
    pq.push({ 0, start });
    costVec[start] = 0;
    while (!pq.empty())
    {
        pair<int, int> top = pq.top();
        pq.pop();

        int curCost = -top.first;
        int curNode = top.second;

        for (int i = 0; i < vec[curNode].size(); ++i)
        {
            int nextNode = vec[curNode][i].first;
            int nextCost = vec[curNode][i].second;

            if (costVec[nextNode] > costVec[curNode] + nextCost)
            {
                costVec[nextNode] = costVec[curNode] + nextCost;
                pq.push({ -costVec[nextNode] , nextNode });
            }
        }
    }

    for (int i = 1; i <= V; ++i)
    {
        if (costVec[i] == INF)
        {
            cout << "INF" << '\n';
        }
        else
        {
            cout << costVec[i] << '\n';
        }        
    }


    return 0;
}