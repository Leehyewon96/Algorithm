#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int E, S, M;
    cin >> E >> S >> M;

    int e = 1;
    int s = 1;
    int m = 1;
    int num = 1;
    while (E != e || S != s || M != m)
    {
        ++num;
        ++e;
        ++s;
        ++m;

        if (e > 15)
        {
            e = 1;
        }

        if (s > 28)
        {
            s = 1;
        }

        if (m > 19)
        {
            m = 1;
        }
    }

    cout << num << '\n';
    return 0;
}