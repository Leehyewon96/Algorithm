#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//bool visited[9];

void DFS(int m, vector<int>& pick, const vector<int>& inputVec)
{
	if (pick.size() == m)
	{
		for (int i = 0; i < pick.size(); ++i)
		{
			cout << pick[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < inputVec.size(); ++i)
	{
		/*if (visited[i])
		{
			continue;
		}
		if (pick.size() > 0 && pick.back() > inputVec[i])
		{
			continue;
		}
		visited[i] = true;*/
		pick.push_back(inputVec[i]);
		DFS(m, pick, inputVec);
		pick.pop_back();
		//visited[i] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<int> inputVec = vector<int>(N);

	for (int i = 0; i < inputVec.size(); ++i)
	{
		cin >> inputVec[i];
	}

	sort(inputVec.begin(), inputVec.end());

	vector<int> pick;
	DFS(M, pick, inputVec);

	return 0;
}