#include <bits/stdc++.h>
using namespace std; 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;

    if (n == 0)
    {
        cout << "0\n";
        return 0;
    }

    string result;
    while (n != 0)
    {
        if (n % -2 == 0)
        {
            result += "0";
            n /= -2;
        }
        else
        {
            result += "1";
            n = (n - 1) / -2;
        }
    }
    reverse(result.begin(), result.end());

    cout << result << '\n';

    return 0;
}