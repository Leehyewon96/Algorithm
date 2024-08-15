#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <memory.h>

using namespace std;

int dp[1000001];

int BinarySearch(const vector<int>& vec, int num, int s, int e)
{
	if (s > e)
	{
		return -1;
	}

	if (s == e)
	{
		return vec[s] == num ? s : -1;
	}

	int mid = (s + e) / 2;

	if (vec[mid] == num)
	{
		return mid;
	}

	if (vec[mid] > num)
	{
		return BinarySearch(vec, num, s, mid);
	}
	else
	{
		return BinarySearch(vec, num, mid + 1, e);
	}
	
}

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

	vector<int> ans;
	for (int i = 0; i < N; ++i)
	{
		if (ans.empty() || ans.back() < vec[i])
		{
			ans.push_back(vec[i]);
		}
		else
		{
			int idx = lower_bound(ans.begin(), ans.end(), vec[i]) - ans.begin();
			ans[idx] = vec[i];
		}
	}

	cout << ans.size();

	return 0;
}