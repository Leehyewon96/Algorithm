#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);

	int T, N, K;
	int a, b;
	cin >> T;
	while (T--)
	{
		cin >> N >> K;

		vector<int> inDegree(N + 1);
		vector<vector<int>> graph(N + 1);
		vector<int> cost(N + 1);
		queue<int> q;
		vector<int> ansVec(N + 1, 0);
		int destination;

		for (int i = 1; i <= N; ++i)
		{
			cin >> cost[i];
			ansVec[i] = cost[i];
		}

		for (int i = 1; i <= K; ++i)
		{
			cin >> a >> b;
			inDegree[b]++;
			graph[a].push_back(b);
		}

		cin >> destination;

		for (int i = 1; i <= N; ++i)
		{
			if (destination == i)
			{
				continue;
			}
			if (inDegree[i] == 0)
			{
				q.push(i);
			}
		}

		for (int i = 0; i < N; ++i)
		{
			if (q.empty())
			{
				break;
			}

			int front = q.front();
			q.pop();

			if (front == destination)
			{
				break;
			}

			for (int j = 0; j < graph[front].size(); ++j)
			{
				int next = graph[front][j];
				inDegree[next]--;
				ansVec[next] = max(ansVec[next], ansVec[front] + cost[next]);
				if (inDegree[next] == 0)
				{
					q.push(next);
				}
			}
		}

		cout << ansVec[destination] << '\n';
	}
	


	return 0;
}