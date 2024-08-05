#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

int arr[501][501];
int ans = 0;

int ud[4] = { -1, 1, 0 ,0 };
int rl[4] = { 0, 0, -1, 1 };

bool visited[501][501];

void Check(int x, int y, int n, int m, int sum, int cnt)
{
	if (cnt == 4)
	{
		ans = max(ans, sum);
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		int nx = x + ud[i];
		int ny = y + rl[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= m)
		{
			continue;
		}

		if (visited[nx][ny])
		{
			continue;
		}

		visited[nx][ny] = true;
		sum += arr[nx][ny];
		Check(nx, ny, n, m, sum, cnt + 1);
		visited[nx][ny] = false;
		sum -= arr[nx][ny];
	}
}

void Check2(int x, int y, int n, int m, int cur,vector<int>& v)
{
	if (v.size() == 3)
	{
		int sum = arr[x][y];
		for (int i = 0; i < 3; ++i)
		{
			int nx = x + ud[v[i]];
			int ny = y + rl[v[i]];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
			{
				return;
			}

			sum += arr[nx][ny];
		}

		ans = max(ans, sum);
		return;
	}

	for (int i = cur; i < 4; ++i)
	{
		v.push_back(i);
		Check2(x, y, n, m, i + 1, v);
		v.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			Check(i, j, N, M, 0, 0);
			memset(visited, false, sizeof(visited));
		}
	}
	
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			vector<int> v;
			Check2(i, j, N, M, 0, v);
		}
	}

	cout << ans;

	return 0;
}