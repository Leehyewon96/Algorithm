#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory.h>
using namespace std;

void Pick(int cur, const vector<int>& inputVec, vector<int>& pick)
{
	if (pick.size() == 6)
	{
		for (int num : pick)
		{
			cout << num << ' ';
		}
		cout << '\n';
	}

	for (int i = cur; i < inputVec.size(); ++i)
	{
		pick.push_back(inputVec[i]);
		Pick(i + 1, inputVec, pick);
		pick.pop_back();
	}
}

int main()
{
	int n;
	vector<int> inputVec;
	int input;
	while (cin >> n && n != 0)
	{
		for (int i = 0; i < n; ++i)
		{
			cin >> input;
			inputVec.push_back(input);
		}
		vector<int> pick;
		Pick(0, inputVec, pick);

		cout << '\n';
		inputVec.clear();
	}
	return 0;
}