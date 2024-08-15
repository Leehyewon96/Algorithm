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

	string str = "";
	cin >> str;

	stack<int> s;
	for (int i = 0; i < str.length(); ++i)
	{
		if (str[i] == '(')
		{
			s.push(-1);
		}
		else if (str[i] == '[')
		{
			s.push(-2);
		}
		else if (str[i] == ')')
		{
			/*if (s.empty())
			{
				cout << 0;
				return 0;
			}*/
			int num = 0;
			while (!s.empty() && s.top() != -1)
			{
				if (s.top() == -2)
				{
					cout << 0;
					return 0;
				}
				num += s.top();
				s.pop();
			}
			if (s.empty())
			{
				cout << 0;
				return 0;
			}
			s.pop();
			if (num == 0)
			{
				num += 2;
			}
			else
			{
				num *= 2;
			}
			s.push(num);
		}
		else if (str[i] == ']')
		{
			/*if (s.empty())
			{
				cout << 0;
				return 0;
			}*/
			int num = 0;
			while (!s.empty() && s.top() != -2)
			{
				if (s.top() == -1)
				{
					cout << 0;
					return 0;
				}
				num += s.top();
				s.pop();
			}
			if (s.empty())
			{
				cout << 0;
				return 0;
			}
			s.pop();
			if (num == 0)
			{
				num += 3;
			}
			else
			{
				num *= 3;
			}
			s.push(num);
		}
	}

	int ans = 0;
	while (!s.empty())
	{
		if (s.top() == -1 || s.top() == -2)
		{
			cout << 0;
			return 0;
		}
		ans += s.top();
		s.pop();
	}
	cout << ans;
	return 0;
}