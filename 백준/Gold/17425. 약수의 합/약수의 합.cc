#include <iostream>
using namespace std;

long long int dp[1000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long int T;
	cin >> T;

	for (long long int i = 1; i < 1000001; ++i)
	{
		for (long long int j = i; j < 1000001; j += i)
		{
			dp[j] += i;
		}

		dp[i] += dp[i - 1];
	}

	while (T)
	{
		T--;
		long long int N;
		cin >> N;
		

		cout << dp[N] << '\n';
	}
	

	return 0;
}