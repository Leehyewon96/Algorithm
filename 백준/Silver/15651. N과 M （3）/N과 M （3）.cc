#include <iostream>
#include <vector>
using namespace std;

//bool visited[9];

void DFS(int m, int n, vector<int>& pick)
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

	for (int i = 1; i <= n; ++i)
	{
		/*if (visited[i])
		{
			continue;
		}*/
		//visited[i] = true;
		pick.push_back(i);
		DFS(m, n, pick);
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
	vector<int> pick;
	DFS(M, N, pick);

	return 0;
}