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

    int n;
    cin >> n;

    int ten = 10;
    int digit = 1;
    int result;
    while (n / ten != 0)
    {
        ten *= 10;
        ++digit;
    }

    if (digit == 1)
    {
        cout << n << '\n';
        return 0;
    }
    else
    {
        ten /= 10;
        result = (n - ten + 1) * digit;
        while (ten != 0)
        {
            ten /= 10;
            --digit;
            result += ten * 9 * digit;
        }
    }

    cout << result << '\n';
    return 0;
}