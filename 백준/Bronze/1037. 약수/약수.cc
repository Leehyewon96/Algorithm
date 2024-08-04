#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, ans;
	cin >> N;

	vector<int> nums = vector<int>(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> nums[i];
	}

	sort(nums.begin(), nums.end());

	if (nums.size() % 2 == 0)
	{
		ans = nums.front() * nums.back();
	}
	else
	{
		ans = nums[nums.size() / 2] * nums[nums.size() / 2];
	}

	cout << ans;
	return 0;
}