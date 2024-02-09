#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define MOD 1000000000;

int D[100001];
int DP(vector<int> vec);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    vector<int> vec;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> M;
        vec.push_back(M);
    }
    cout << DP(vec) << '\n';
    return 0;
}

int DP(vector<int> vec)
{
    int max = 1;
    D[0] = 1;
    for (int i = 0; i < vec.size(); ++i)
    {
        D[i] = 1;
        for (int j = i - 1; j >= 0; --j)
        {
            if (vec[j] < vec[i] && D[i] < D[j] + 1)
            {
                D[i] = D[j] + 1;
            }
        }

        if (max < D[i])
        {
            max = D[i];
        }
    }

    return max;
}