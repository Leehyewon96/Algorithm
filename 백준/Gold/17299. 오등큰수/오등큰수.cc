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
	vector<int> cntVec(1000001);
	vector<int> vec(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> vec[i];
		cntVec[vec[i]]++;
	}

	stack<int> s;
	stack<int> ans;
	for (int i = N - 1; i >= 0;--i)
	{
		if (s.empty())
		{
			ans.push(-1);
		}
		else
		{
			while (!s.empty())
			{
				if (cntVec[vec[s.top()]] > cntVec[vec[i]])
				{
					ans.push(vec[s.top()]);
					break;
				}
				else
				{
					s.pop();
				}
			}

			if (s.empty())
			{
				ans.push(-1);
			}
		}

		s.push(i);
	}

	while (!ans.empty())
	{
		cout << ans.top() << ' ';
		ans.pop();
	}

	return 0;
}