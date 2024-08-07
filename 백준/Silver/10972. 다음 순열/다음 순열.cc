#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory.h>
using namespace std;
int main()
{
	int N;
	cin >> N;
	vector<int> inputVec(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> inputVec[i];
	}


	if (next_permutation(inputVec.begin(), inputVec.end()))
	{
		for (int i : inputVec)
		{
			cout << i << ' ';
		}
	}
	else
	{
		cout << -1;
	}

	return 0;
}