#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

int arr[21][21];
int diff = 4501;
bool visited[21];

void Check(int cur, int teamCnt, int n)
{
	if (teamCnt >= 1 && teamCnt <= n/2)
	{
		int teamOneTotal = 0;
		for (int i = 0; i < n; ++i)
		{
			if (!visited[i])
			{
				continue;
			}
			for (int j = 0; j < n; ++j)
			{
				if (!visited[j])
				{
					continue;
				}
				if (i != j)
				{
					teamOneTotal += arr[i][j];
				}
			}
		}

		int teamTwoTotal = 0;
		for (int i = 0; i < n; ++i)
		{
			if (visited[i])
			{
				continue;
			}
			for (int j = 0; j < n; ++j)
			{
				if (visited[j])
				{
					continue;
				}
				if (i != j)
				{
					teamTwoTotal += arr[i][j];
				}
			}
		}
		diff = min(diff, abs(teamOneTotal - teamTwoTotal));
		//return;
	}

	for (int i = cur; i < n; ++i)
	{
		if (visited[i])
		{
			continue;
		}

		visited[i] = true;
		Check(i + 1, teamCnt + 1, n);
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
	vector<int> team;
	Check(0, 0, N);

	cout << diff;

	return 0;
}