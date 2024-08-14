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

	string str;
	cin >> str;

	stack<int> s;
	long long ans = 0;
	for(int i = 0; i < str.length(); ++i)
	{
		if (str[i] == '(')
		{
			s.push(-1);
		}
		else if (str[i] >= '0' && str[i] <= '9')
		{
			if (i != str.length() - 1 && str[i + 1] == '(')
			{
				s.push(str[i] - '0');
			}
			else
			{
				s.push(1);
			}
		}
		else if(str[i] == ')')
		{
			int cnt = 0;
			while (s.top() != -1)
			{
				cnt += s.top();
				s.pop();
			}
			s.pop();
			cnt *= s.top();
			s.pop();
			s.push(cnt);
		}
	}

	while (!s.empty())
	{
		ans+=s.top();
		s.pop();
	}
	cout << ans;
	return 0;
}