#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>

using namespace std;

int visited[20001];

bool IsBipartite(const vector<vector<int>>& vec, int n)
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j < vec[i].size(); ++j)
		{
			if (visited[i] == visited[vec[i][j]])
			{
				return false;
			}
		}
	}

	return true;
}

void BFS(const vector<vector<int>>& vec, int start)
{
	queue<int> q;
	q.push(start);

	while (!q.empty())
	{
		int front = q.front();
		q.pop();

		if (visited[front] == 0)
		{
			visited[front] = 1;
		}

		for (int i = 0; i < vec[front].size(); ++i)
		{
			if (visited[vec[front][i]] != 0)
			{
				continue;
			}

			if (visited[front] == 1)
			{
				visited[vec[front][i]] = 2;
			}
			else if (visited[front] == 2)
			{
				visited[vec[front][i]] = 1;
			}

			q.push(vec[front][i]);
		}
	}
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);

	int K, V, E;
	cin >> K;

	while (K--)
	{
		cin >> V >> E;
		vector<vector<int>> vec(V + 1);
		int a, b;
		for (int i = 0; i < E; ++i)
		{
			cin >> a >> b;
			vec[a].push_back(b);
			vec[b].push_back(a);
		}

		for (int i = 1; i <= V; ++i)
		{
			sort(vec[i].begin(), vec[i].end());
		}


		for (int i = 1; i <= V; ++i)
		{
			if (visited[i])
			{
				continue;
			}

			BFS(vec, i);
		}
		

		if (IsBipartite(vec, V))
		{
			cout << "YES" << '\n';
		}
		else
		{
			cout << "NO" << '\n';
		}
		memset(visited, 0, sizeof(visited));
	}

	return 0;
}