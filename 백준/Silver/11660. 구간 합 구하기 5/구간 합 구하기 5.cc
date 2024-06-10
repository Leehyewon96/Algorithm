#include <iostream>
#include <vector>
#include <map>
using namespace std;

int arr[1025][1025];
int sum[1025][1025];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            cin >> arr[i][j];
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + arr[i][j];
        }
    }

    int r, c, r2, c2;
    for (int i = 0; i < M; ++i)
    {
        cin >> r >> c >> r2 >> c2;

        cout << sum[r2][c2] - sum[r - 1][c2] - sum[r2][c - 1] + sum[r - 1][c - 1] << '\n'; //42 - 
    }

    return 0;
}