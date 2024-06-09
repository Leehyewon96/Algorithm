#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>
using namespace std;

bool visited[10001];

bool Comp(const pair<int, int> vec1, const pair<int, int>& vec2)
{
    return vec1.second < vec2.second;
}
bool FindPath(const vector<vector<pair<int, int>>>& pathVec, int cur, int target, int minCost)
{
    //minCost 이상인 경로로만 target에 도착할 수 있는지 검사
    queue<int> q;
    q.push(cur);

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        if (front == target)
        {
            return true;
        }

        for (int i = 0; i < pathVec[front].size(); ++i)
        {
            int nextPoint = pathVec[front][i].first;
            int nextCost = pathVec[front][i].second;
            if (visited[nextPoint] || nextCost < minCost)
            {
                continue;
            }

            visited[nextPoint] = true;
            q.push(nextPoint);
        }
    }

    return false;
}

int BinarySearch(const vector<vector<pair<int, int>>>& pathVec, int left, int right, int start, int target)
{
    if (left > right)
    {
        return right;
    }

    int mid = (left + right) / 2;
    memset(visited, false, sizeof(visited));
    if (FindPath(pathVec, start, target, mid))
    {
        return BinarySearch(pathVec, mid + 1, right, start, target);
    }
    else 
    {
        return BinarySearch(pathVec, left, mid - 1, start, target);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, int>>> pathVec(N+1);
    int s, e, c;
    for (int i = 0; i < M; ++i)
    {
        cin >> s >> e >> c;
        pathVec[s].push_back(make_pair(e, c));
        pathVec[e].push_back(make_pair(s, c)); // 양방향이므로 반대방향까지 저장
    }

    int inStart, inEnd;

    cin >> inStart >> inEnd;

    int maxCost = 0;
    for (int i = 1; i < pathVec.size(); ++i)
    {
        sort(pathVec[i].begin(), pathVec[i].end(), Comp);
        if (!pathVec[i].empty())
        {
            maxCost = max(maxCost, pathVec[i].back().second);
        }
        
    }

    cout << BinarySearch(pathVec, 1, maxCost, inStart, inEnd);
    return 0;
}