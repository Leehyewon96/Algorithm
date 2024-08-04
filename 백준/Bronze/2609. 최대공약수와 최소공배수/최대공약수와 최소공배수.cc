#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b;
	
	cin >> a >> b;
	
	if (a < b)
	{
		int t = a;
		a = b;
		b = t;
	}

	int originB = b;

	int r = a % b;
	while (r != 0)
	{
		int tempB = b;
		b = r;
		r = tempB % r;
		
	}

	cout << b << '\n';

	cout << a * originB / b;

	return 0;
}