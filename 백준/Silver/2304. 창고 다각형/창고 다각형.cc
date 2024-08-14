#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <memory.h>

using namespace std;

bool Comp(pair<int, int> p1, pair<int, int> p2)
{
	return p1.first < p2.first;
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	int N;
	cin >> N;

	vector<pair<int, int>> vec(N);
	int L, H;
	for(int i = 0; i < N; ++i)
	{
		cin >> L >> H;

		vec[i] = { L, H };
	}
	sort(vec.begin(), vec.end(), Comp);

	int highest = 0;
	int ans = 0;
	for (int i = 0; i < vec.size(); ++i)
	{
		if (vec[highest].second <= vec[i].second)
		{
			int width = abs(vec[i].first - vec[highest].first);
			ans += vec[highest].second * width;
			highest = i;
		}
	}

	int highestRev = vec.size() - 1;
	for (int i = vec.size() - 1; i >= 0; --i)
	{
		if (vec[highestRev].second < vec[i].second)
		{
			int width = abs(vec[i].first - vec[highestRev].first);
			ans += vec[highestRev].second * width;
			highestRev = i;
		}
	}

	cout << ans + vec[highestRev].second;

	return 0;
}