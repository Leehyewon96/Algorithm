#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int Kying(vector<int> vec)
{
    int M = vec[0];
    int N = vec[1];

    for (int i = vec[2] - 1; i < M * N; i += M)
    {
        if (i % N == vec[3] - 1)
        {
            return i + 1;
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> vec;
    int N;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            cin >> N;
            vec.push_back(N);
        }
        cout << Kying(vec) << '\n';
        vec.clear();
    }

    return 0;
}