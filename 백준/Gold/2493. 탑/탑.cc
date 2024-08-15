#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <memory.h>

using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N;
	cin >> N;
	vector<int> vec(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> vec[i];
	}

	stack<int> s;
	for (int i = 0; i < N; ++i)
	{
		if (s.empty())
		{
			cout << 0 << ' ';
		}
		else
		{
			while (!s.empty())
			{
				if (vec[s.top()] >= vec[i])
				{
					cout << s.top() + 1 << ' ';
					break;
				}
				else
				{
					s.pop();
				}
			}

			if (s.empty())
			{
				cout << 0 << ' ';
			}
		}
		s.push(i);
	}

	

	return 0;
}