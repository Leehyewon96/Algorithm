#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;
int ans = 0;

void DFS(int sum, const int num)
{
	if (sum == num)
	{
		ans++;
		return;
	}

	if (sum > num)
	{
		return;
	}

	for (int i = 1; i <= 3; ++i)
	{
		sum += i;
		DFS(sum, num);
		sum -= i;
	}
}

int main()
{
	int T;
	cin >> T;

	int num;
	while (T--)
	{
		cin >> num;
		DFS(0, num);
		cout << ans << '\n';
		ans = 0;
	}
	return 0;
}