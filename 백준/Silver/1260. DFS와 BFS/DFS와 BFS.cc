#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>

using namespace std;

bool visited[1002];

void DFS(const vector<vector<int>>& vec, int cur)
{
	cout << cur << ' ';

	for (int i = 0; i < vec[cur].size(); ++i)
	{
		if (visited[vec[cur][i]])
		{
			continue;
		}
		visited[vec[cur][i]] = true;
		DFS(vec, vec[cur][i]);
		//visited[vec[cur][i]] = false;
	}
}

void BFS(const vector<vector<int>>& vec, int start)
{
	queue<int> q;
	q.push(start);
	
	while (!q.empty())
	{
		int front = q.front();
		cout << front << ' ';
		q.pop();

		for (int i = 0; i < vec[front].size(); ++i)
		{
			if (visited[vec[front][i]])
			{
				continue;
			}

			visited[vec[front][i]] = true;
			q.push(vec[front][i]);
		}
	}
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N, M, V;
	cin >> N >> M >> V;

	vector<vector<int>> vec(N + 1);

	int a, b;
	for (int i = 0; i < M; ++i)
	{
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	for (int i = 1; i <= N; ++i)
	{
		sort(vec[i].begin(), vec[i].end());
	}

	visited[V] = true;
	DFS(vec, V);

	cout << '\n';
	memset(visited, false, sizeof(visited));
	visited[V] = true;
	BFS(vec, V);

	return 0;
}