#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool Comp(pair<int, int> p1, pair<int, int> p2)
{
    return p1.first == p2.first ? p1.second < p2.second : p1.first < p2.first;
}

    
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;

    int x, y;
    vector<pair<int, int>> vec;
    for (int i = 0; i < N; ++i)
    {
        cin >> x >> y;
        vec.push_back({ x, y });
    }

    sort(vec.begin(), vec.end(), Comp);

    for (int i = 0; i < N; ++i)
    {
        cout << vec[i].first << ' ' << vec[i].second << '\n';
    }
    return 0;
}