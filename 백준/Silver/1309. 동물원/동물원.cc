#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <memory.h>

#define MOD 9901;

using namespace std;
int dp[100001][3];

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N; 
	cin >> N;

	dp[1][0] = 1;
	dp[1][1] = 1;
	dp[1][2] = 1;

	for (int i = 2; i <= N; ++i)
	{
		dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % MOD;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
		dp[i][2] = (dp[i - 1][1] + dp[i - 1][0] + dp[i - 1][2]) % MOD;
	}

	cout << (dp[N][0] + dp[N][1] + dp[N][2]) % MOD;

	//dp[n][0] = dp[n - 1][1];
	//dp[n][1] = dp[n -1][0];
	//dp[n][2] = dp[n - 1][1] +  dp[n - 1][0];

	return 0;
}