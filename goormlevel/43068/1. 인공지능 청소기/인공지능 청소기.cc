#include <iostream>
using namespace std;

int main() {
	int T, X, Y, N;
	cin >> T;
	while (T--)
	{
		cin >> X >> Y >> N;
		if(abs(X) + abs(Y) > N)
		{
			cout << "NO" << '\n';
			continue;
		}
		
		if(((abs(X) + abs(Y)) % 2 != N % 2))
			{
			 cout << "NO" << '\n';
			 continue;
			}
			 
			 cout << "YES" << '\n';
	}

	return 0;
}