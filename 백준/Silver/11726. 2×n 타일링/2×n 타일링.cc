#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory.h>
using namespace std;

int dp[1001];

int DP(int N)
{
	if (N == 1)
	{
		return 1;
	}

	if (N == 2)
	{
		return 2;
	}

	if (dp[N] > 0)
	{
		return dp[N];
	}

	dp[N] = DP(N - 1) + DP(N - 2);
	return dp[N] % 10007;
}


int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	
	int N;
	cin >> N;

	dp[1] = 1;
	dp[2] = 2;

	
	cout << DP(N);

	return 0;
}