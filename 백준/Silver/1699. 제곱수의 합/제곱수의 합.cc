#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define MOD 1000000000;

int D[100000];
int DP(int vec);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    cout << DP(N) << '\n';
    return 0;
}

int DP(int num)
{
    for (int i = 1; i <= num; ++i)
    {
        D[i] = i;
        for (int j = 1; i >= j * j; ++j)
        {
            if (D[i] > 1 + D[i - j * j])
            {
                D[i] = 1 + D[i - j * j];
            }
        }
    }
    return D[num];
   
}