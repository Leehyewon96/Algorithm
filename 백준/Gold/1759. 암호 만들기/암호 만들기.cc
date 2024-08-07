#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

bool CheckContain(const string& pick)
{
	int gather = 0;
	int consonant = 0;
	for (int i = 0; i < pick.size(); ++i)
	{
		switch (pick[i])
		{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			gather++;
			break;
		default:
			consonant++;
			break;
		}
	}

	if (gather >= 1 && consonant >= 2)
	{
		return true;
	}

	return false;
}

void Check(int n, int cur, string pick, const string& inputVec)
{
	if (pick.size() == n)
	{
		if (CheckContain(pick))
		{
			cout << pick;
			cout << '\n';
			return;
		}

	}

	for (int i = cur; i < inputVec.size(); ++i)
	{
		pick.push_back(inputVec[i]);
		Check(n, i + 1, pick, inputVec);
		pick.pop_back();
	}
}


int main()
{
	int N, M;
	cin >> N >> M;

	string inputVec = "";
	char ch;
	for (int i = 0; i < M; ++i)
	{
		cin >> ch;
		inputVec.push_back(ch);
	}


	string pick;
	sort(inputVec.begin(), inputVec.end());
	Check(N, 0, pick, inputVec);
	return 0;
}