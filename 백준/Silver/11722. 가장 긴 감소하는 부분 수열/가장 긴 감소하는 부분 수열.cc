#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <memory.h>

using namespace std;
int dp[1001];

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N; 
	cin >> N;

	vector<int> vec(N + 1);

	for (int i = 1; i <= N; ++i)
	{
		cin >> vec[i];
	}

	int ans = 0;
	dp[1] = 1;
	for (int i = 1; i <= N; ++i)
	{
		dp[i] = 1;
		
		for (int j = 0; j < i; ++j)
		{
			if (vec[i] < vec[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		ans = max(ans, dp[i]);
	}

	cout << ans;

	return 0;
}