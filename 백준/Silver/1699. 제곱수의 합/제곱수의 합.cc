#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <memory.h>

using namespace std;
int dp[100001];
int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N;
	cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		dp[i] = i;
	}

	for (int i = 1; i <= sqrtf(N); ++i)
	{
		dp[i * i] = 1;
	}

	for (int i = 3; i <= N; ++i)
	{
		for (int j = 1; i >= j*j; ++j)
		{
			dp[i] = min(dp[i], dp[i - j *j] + 1);
		}
	}

	cout << dp[N];

	return 0;
}