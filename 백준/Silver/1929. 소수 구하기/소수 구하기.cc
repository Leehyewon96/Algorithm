#include <iostream>
using namespace std;

int dp[1000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int M, N;
	cin >> M >> N;
	dp[1] = -1;
	for(int i = 2; i * i < 1000001; ++i)
	{
		if (dp[i] != -1)
		{
			for (int j = i * i; j < 1000001; j += i)
			{
				dp[j] = -1;
			}
		}
	}

	for (int i = M; i <= N; ++i)
	{
		if (dp[i] == 0)
		{
			cout << i << '\n';
		}
	}

	return 0;
}