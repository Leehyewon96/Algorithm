#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory.h>

using namespace std;

long long dp[91][2];

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N;
	cin >> N;

	dp[1][1] = 1;

	for (int i = 2; i <= N; ++i)
	{
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}
	
	//dp[n][0] = dp[n - 1][0] + dp[n - 1][1];
	//dp[n][1] = dp[n - 1][0];

	cout << dp[N][0] + dp[N][1] << '\n';
	
	return 0;
}