#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

int arr[11][11];
int ans = -1e4;
bool visited[11][11];
pair<int, int> q[11];
int N, M, K;

bool Check(int cx, int cy, int cnt)
{
	for (int i = 0; i < cnt; ++i)
	{
		if (cx == q[i].first && cy == q[i].second + 1) return false;
		if (cx == q[i].first && cy == q[i].second - 1) return false;
		if (cx == q[i].first + 1 && cy == q[i].second) return false;
		if (cx == q[i].first - 1 && cy == q[i].second) return false;
	}
	
	return true;
}

void DFS(int cnt, int sum, int k)
{
	if (cnt == k)
	{
		ans = max(ans, sum);
		return;
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (!visited[i][j] && Check(i, j, cnt))
			{
				visited[i][j] = true;
				q[cnt] = { i, j };
				DFS(cnt + 1, sum + arr[i][j], k);
				visited[i][j] = false;
			}
		}
	}
}

int main()
{
	
	cin >> N >> M >> K;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> arr[i][j];
		}
	}
	
	DFS(0, 0, K);
	cout << ans;
	return 0;
}