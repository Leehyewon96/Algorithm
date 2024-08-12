#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>

using namespace std;

int visited[100001];

int BFS(int n, int k)
{
	queue<int> q;
	q.push(n);
	visited[n] = 1;

	while (!q.empty())
	{
		int front = q.front();
		q.pop();

		if (front == k)
		{
			break;
		}

		int next = front;
		if (front - 1 >= 0)
		{
			next = front - 1;
			if (!visited[next] || visited[next] > visited[front])
			{
				visited[next] = visited[front] + 1;
				q.push(next);
			}
		}

		if (front + 1 <= 100000)
		{
			next = front + 1;
			if (!visited[next] || visited[next] > visited[front])
			{
				visited[next] = visited[front] + 1;
				q.push(next);
			}
		}

		if (front * 2 <= 100000)
		{
			next = front * 2;
			if (!visited[next] || visited[next] > visited[front])
			{
				visited[next] = visited[front] + 1;
				q.push(next);
			}
		}
	}

	return --visited[k];
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N, K;
	cin >> N >> K;

	
	cout << BFS(N, K);

	return 0;
}