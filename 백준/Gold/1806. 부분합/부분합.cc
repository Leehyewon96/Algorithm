#include <iostream>
#include <queue>
#include <climits>

using namespace std;

int arr[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, S;

    cin >> N >> S;

    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }

    if (N == 1)
    {
        if (arr[0] == S)
        {
            cout << 1;
        }
        else
        {
            cout << 0;
        }

        return 0;
    }

    int s = 0;
    int e = 0;

    int res = INT_MAX;
    int sum = arr[0];

    while (s <= e && e < N)
    {
        if (sum >= S)
        {
            res = min(res, e - s + 1);
        }

        if (sum < S)
        {
            e++;
            sum += arr[e];
            
        }
        else
        {
            sum -= arr[s];
            s++;
        }
    }

    if (res == INT_MAX)
    {
        res = 0;
    }

    cout << res;
    return 0;
}