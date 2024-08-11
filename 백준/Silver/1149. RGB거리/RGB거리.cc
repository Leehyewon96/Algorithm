#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <memory.h>

using namespace std;
int dp[1001][3];

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N; 
	cin >> N;

	vector<vector<int>> vec(N, vector<int>(3));
	for (int i = 0; i < N; ++i)
	{
		cin >> vec[i][0] >> vec[i][1] >> vec[i][2];
	}

	for (int i = 0; i < N; ++i)
	{
		dp[i][0] = vec[i][0];
		dp[i][1] = vec[i][1];
		dp[i][2] = vec[i][2];
	}

	for (int i = 1; i < N; ++i)
	{
		dp[i][0] += min(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] += min(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] += min(dp[i - 1][0], dp[i - 1][1]);
	}

	cout << min(dp[N - 1][0], min(dp[N - 1][1], dp[N - 1][2]));

	return 0;
}