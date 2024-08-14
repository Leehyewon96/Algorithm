#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>

using namespace std;

int visited[100001];

void BFS(int n, int k)
{
	queue<int> q;
	q.push(n);
	
	while (!q.empty())
	{
		int front = q.front();
		q.pop();
		visited[n] = n;
		
		if (front == k)
		{
			break;
		}

		int next = front - 1;
		if (next >= 0 && visited[next] == -1)
		{
			q.push(next);
			visited[next] = front;
		}

		next = front + 1;
		if (next <= 100000 && visited[next] == -1)
		{
			q.push(next);
			visited[next] = front;
		}

		next = front * 2;
		if (next <= 100000 && visited[next] == -1)
		{
			q.push(next);
			visited[next] = front;
		}
	}

	
	int cur = k;
	vector<int> route;
	while (cur != n && cur >= 0)
	{
		route.push_back(cur);
		cur = visited[cur];
	}
	route.push_back(n);

	cout << route.size() - 1 << '\n';
	for (int i = route.size() - 1; i >= 0; --i)
	{
		cout << route[i] << ' ';
	}
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N, K;
	cin >> N >> K;

	memset(visited, -1, sizeof(visited));
	
	BFS(N, K);

	return 0;
}