#include <iostream>
using namespace std;

int GCD(int a, int b)
{
	if (b == 0)
	{
		return a;
	}

	return GCD(b, a % b);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	int x, y, cx, cy;
	while (T--)
	{
		cin >> x >> y >> cx >> cy;

		int curX = 1;
		int curY = 1;
		int year = -1;
		int gcd = GCD(x, y);
		int lcm = x * y / gcd;
		
		for (int i = cx - 1; i < lcm; i += x)
		{
			if (i % y == cy - 1)
			{
				year = i + 1;
				break;
			}
		}
		cout << year << '\n';
	}

	return 0;
}