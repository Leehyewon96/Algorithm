#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int DP(int n);

int main()
{
    int N;
    cin >> N;

    vector<int> D(N + 1, -1);

    D[1] = 0;
    for (int i = 2; i < N + 1; ++i)
    {
        D[i] = D[i - 1] + 1;
        if (i % 2 == 0)
        {
            D[i] = min(D[i], D[i / 2] + 1);
        }
        if (i % 3 == 0)
        {
            D[i] = min(D[i], D[i / 3] + 1);
        }
    }
    cout << D[N];
    return 0;
}