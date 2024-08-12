#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int N, M;

vector<int> linkedVec[1001];
int visited[1001];
int ans = 0;
vector<int> vec;
int used[1001];

void DFS(int curNum)
{
    if (visited[curNum])
    {
        return;
    }
    
    visited[curNum] = true;
    vec.push_back(curNum);

    for (int i = 0; i < linkedVec[curNum].size(); ++i)
    {
        int next = linkedVec[curNum][i];
        if (!visited[next])
        {
            DFS(next);
            
        }
    }
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    cin >> N >> M;
    int node1, node2;
    for (int i = 0; i < M; ++i)
    {
        cin >> node1 >> node2;
        linkedVec[node1].push_back(node2);
        linkedVec[node2].push_back(node1);
    }

    for (int i = 1; i <= N; ++i)
    {
        sort(linkedVec[i].begin(), linkedVec[i].end());
    }

    for (int i = 1; i <= N; ++i)
    {
        vec.clear();
        DFS(i);

        int usedCnt = 0;
        for (int j = 0; j < vec.size(); ++j)
        {
            if (!used[vec[j]])
            {
                used[vec[j]] = true;
                usedCnt++;
            }
            
        }

        if (vec.size() != 0 && usedCnt == vec.size())
        {
            ++ans;
        }
    }
   
    cout << ans << '\n';
    return 0;
}