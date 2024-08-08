#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory.h>
using namespace std;

int arr[11][11];
bool visited[11];

int ans = 121000001;

int ud[4] = { -1, 1, 0, 0 };
int rl[4] = { 0, 0, -1, 1 };

void Check(int cnt, int n, int cur, int start, int sum)
{
	if (cnt == n - 1)
	{
		if(arr[cur][start] != 0)
		{
			ans = min(ans, sum + arr[cur][start]);
		}
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		if (visited[i])
		{
			continue;
		}

		if (arr[cur][i] == 0)
		{
			continue;
		}

		visited[i] = true;
		Check(cnt + 1, n, i, start, sum + arr[cur][i]);
		visited[i] = false;
	}
}

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; ++i)
	{
		visited[i] = true;
		Check(0, N, i, i, 0);
		visited[i] = false;
	}

	cout << ans;
	return 0;
}