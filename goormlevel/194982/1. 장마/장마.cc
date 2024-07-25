#include <iostream>
#include <vector>
using namespace std;
int main() {
	int N, M;
	cin >> N >> M;

	vector<int> house = vector<int>(N + 1);
	for (int i = 1; i <= N; ++i)
	{
		cin >> house[i];
	}

	vector<pair<int, int>> rain;
	int s, e;
	rain.push_back({ 0, 0 });
	for (int i = 0; i < M; ++i)
	{
		cin >> s >> e;
		rain.push_back({ s, e });
	}

	for (int i = 1; i <= M; i++)
	{
		for (int j = rain[i].first; j <= rain[i].second; ++j)
		{
			house[j]++;
		}

		if (i >= 3 && i % 3 == 0)
		{
			vector<bool> drainage(N + 1);

			for (int j = i - 2; j <= i; ++j)
			{
				for (int k = rain[j].first; k <= rain[j].second; ++k)
				{
					drainage[k] = true;
				}
			}
			for (int j = 1; j <= N; ++j)
			{
				if (drainage[j])
				{
					house[j]--;
				}
			}
			
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		cout << house[i] << ' ';
	}

	return 0;
}