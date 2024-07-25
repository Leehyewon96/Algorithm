#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool Comp(int a, int b)
{
	return a > b;
}

int main() {
	int N;
	cin >> N;

	vector<char> ans;
	while (N--)
	{
		char victory ='A';
		int A;
		cin >> A;
		vector<int> vecA = vector<int>(A);
		for (int i = 0; i < vecA.size(); ++i)
		{
			cin >> vecA[i];
		}
		sort(vecA.begin(), vecA.end(), Comp);

		int B;
		cin >> B;
		vector<int> vecB = vector<int>(B);
		for (int i = 0; i < vecB.size(); ++i)
		{
			cin >> vecB[i];
		}
		sort(vecB.begin(), vecB.end(), Comp);

		int turn = vecA.size() <= vecB.size() ? vecA.size() : vecB.size();
		int i = 0;
		for (i = 0; i < turn; ++i)
		{
			if (vecA[i] > vecB[i])
			{
				victory = 'A';
				break;
			}
			else if (vecA[i] < vecB[i])
			{
				victory = 'B';
				break;
			}
		}
		if (i == turn)
		{
			if (vecA.size() > vecB.size())
			{
				victory = 'A';
			}
			else if (vecA.size() < vecB.size())
			{
				victory = 'B';
			}
			else {
				victory = 'D';
			}

		}

		ans.push_back(victory);
	}

	for (int i = 0; i < ans.size(); ++i)
	{
		cout << ans[i] << '\n';
	}
	cout << '\n';
	return 0;
}