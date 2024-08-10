#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory.h>
using namespace std;

int dp[1001];


int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	
	int N; 
	cin >> N;
	vector<int> costVec(N + 1);
	for (int i = 1; i <= N; ++i)
	{
		cin >> costVec[i];
		dp[i] = costVec[i];
	}

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j < i; ++j)
		{
			dp[i] = max(dp[i], dp[i - j] + dp[j]);
		}
	}

	cout << dp[N];

	return 0;
}