#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory.h>
using namespace std;

int ans = 0;

bool visited[9];

void Check(vector<int>& pick, const vector<int>& input)
{
	if (pick.size() == input.size())
	{
		int sum = 0;
		for (int i = 0; i < pick.size() - 1; ++i)
		{
			sum += abs(pick[i] - pick[i + 1]);
		}
		ans = max(ans, sum);
		return;
	}

	for (int i = 0; i < input.size(); ++i)
	{
		if (visited[i])
		{
			continue;
		}
		visited[i] = true;
		pick.push_back(input[i]);
		Check(pick, input);
		visited[i] = false;
		pick.pop_back();
	}
}

int main()
{
	int N;
	cin >> N;

	vector<int> inputVec(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> inputVec[i];
	}
	vector<int> pick;
	Check(pick, inputVec);
	cout << ans;

	return 0;
}