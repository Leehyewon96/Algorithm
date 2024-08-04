#include <iostream>

using namespace std;

int main()
{
	long long int N;
	
	while (cin >> N)
	{
		long long int ans = 1;
		long long int num = 1;
		while (1)
		{
			if (num % N == 0)
			{
				break;
			}

			num = num * 10 + 1;
			num %= N;
			ans++;
		}

		cout << ans << '\n';
	}

	

	return 0;
}