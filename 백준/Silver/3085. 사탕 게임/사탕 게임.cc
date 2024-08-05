#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char arr[51][51];
int ans = 0;

void Check(int x, int y, int n)
{
	if (x + 1 < n)
	{
		int temp = arr[x][y];
		arr[x][y] = arr[x + 1][y];
		arr[x + 1][y] = temp;

		int cnt = 1;
		for (int i = 0; i < n - 1; ++i)
		{
			if (arr[x][i] == arr[x][i + 1])
			{
				cnt++;
			}
			else
			{
				ans = max(ans, cnt);
				cnt = 1;
			}
		}
		ans = max(ans, cnt);

		cnt = 1;
		for (int i = 0; i < n - 1; ++i)
		{
			if (arr[x + 1][i] == arr[x + 1][i + 1])
			{
				cnt++;
			}
			else
			{
				ans = max(ans, cnt);
				cnt = 1;
			}
		}
		ans = max(ans, cnt);

		cnt = 1;
		for (int i = 0; i < n - 1; ++i)
		{
			if (arr[i][y] == arr[i + 1][y])
			{
				cnt++;
			}
			else
			{
				ans = max(ans, cnt);
				cnt = 1;
			}
		}
		ans = max(ans, cnt);


		temp = arr[x][y];
		arr[x][y] = arr[x + 1][y];
		arr[x + 1][y] = temp;
	}

	if (y + 1 < n)
	{
		int temp = arr[x][y];
		arr[x][y] = arr[x][y + 1];
		arr[x][y + 1] = temp;

		int cnt = 1;
		for (int i = 0; i < n - 1; ++i)
		{
			if (arr[i][y] == arr[i + 1][y])
			{
				cnt++;
			}
			else
			{
				ans = max(ans, cnt);
				cnt = 1;
			}
		}
		ans = max(ans, cnt);

		cnt = 1;
		for (int i = 0; i < n - 1; ++i)
		{
			if (arr[i][y + 1] == arr[i + 1][y + 1])
			{
				cnt++;
			}
			else
			{
				ans = max(ans, cnt);
				cnt = 1;
			}
		}
		ans = max(ans, cnt);

		cnt = 1;
		for (int i = 0; i < n - 1; ++i)
		{
			if (arr[x][i] == arr[x][i + 1])
			{
				cnt++;
			}
			else
			{
				ans = max(ans, cnt);
				cnt = 1;
			}
		}
		ans = max(ans, cnt);


		temp = arr[x][y];
		arr[x][y] = arr[x][y + 1];
		arr[x][y + 1] = temp;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	string str;
	for (int i = 0; i < N; ++i)
	{
		cin >> str;
		for (int j = 0; j < N; ++j)
		{
			arr[j][i] = str[j];
		}
	}

	
	for (int i = 0; i < N; ++i)
	{
		int cnt = 1;
		for (int j = 0; j < N - 1; ++j)
		{
			if (arr[j][i] == arr[j + 1][i])
			{
				cnt++;
			}
			else
			{
				ans = max(ans, cnt);
				cnt = 1;
			}
		}
		ans = max(ans, cnt);

		cnt = 1;
		for (int j = 0; j < N - 1; ++j)
		{
			if (arr[i][j] == arr[i][j + 1])
			{
				cnt++;
			}
			else
			{
				ans = max(ans, cnt);
				cnt = 1;
			}
		}
		ans = max(ans, cnt);

	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			Check(j, i, N);
		}
	}
	

	cout << ans;


	return 0;
}