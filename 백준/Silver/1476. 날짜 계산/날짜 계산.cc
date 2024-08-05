#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int E, S, M;
	int e = 1;
	int s = 1;
	int m = 1;

	cin >> E >> S >> M;

	int year = 1;
	while (e != E || s != S || m != M)
	{
		year++;
		e++;
		s++;
		m++;

		if (e > 15)
		{
			e = 1;
		}

		if (s > 28)
		{
			s = 1;
		}

		if (m > 19)
		{
			m = 1;
		}
	}

	cout << year;
	

	return 0;
}