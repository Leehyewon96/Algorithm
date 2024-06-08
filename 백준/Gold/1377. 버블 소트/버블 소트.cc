#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;

    int num;
    vector<pair<int, int>> vec;
    for (int i = 0; i < N; ++i)
    {
        cin >> num;
        vec.push_back({ num, i });
    }
    sort(vec.begin(), vec.end());

    int diff = 0;
    for (int i = 0; i < N; ++i)
    {
        diff = max(diff, vec[i].second - i);
    }

    cout << ++diff;
    return 0;
}