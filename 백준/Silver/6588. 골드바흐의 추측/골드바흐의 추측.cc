#include <iostream>
using namespace std;

int dp[1000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	dp[1] = -1;
	for (int i = 2; i * i < 1000001; ++i)
	{
		if (dp[i] != -1)
		{
			for (int j = i * i; j < 1000001; j += i)
			{
				dp[j] = -1;
			}
		}
	}
	
	int num;
	while (cin >> num && num != 0)
	{
		int a = -1;
		
		for (int i = 3; i < num; i += 2)
		{
			if (dp[i] == 0 && dp[num - i] == 0)
			{
				a = i;
				break;
			}
		}

		if (a == -1)
		{
			cout << "Goldbach's conjecture is wrong." << '\n';
			continue;
		}

		cout << num << " = " << a << " + " << num - a << '\n';
	}

	return 0;
}