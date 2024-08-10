#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory.h>

using namespace std;
int dp[100001];
int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N;
	cin >> N;
	vector<int> vec(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> vec[i];
	}

	int ans = vec[0];
	dp[0] = vec[0];
	for (int i = 1; i < N; ++i)
	{
		dp[i] = max(vec[i], dp[i - 1] + vec[i]);
		ans = max(ans, dp[i]);
	}

	cout << ans;


	return 0;
}