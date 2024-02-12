#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int Check(vector<string> &arr);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<string> a(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> a[i];
    }

    int maxResult = 1;
    for (int i = 0; i < a.size(); ++i)
    {
        for (int j = 0; j < a.size() - 1; ++j)
        {
            char temp = a[i][j];
            a[i][j] = a[i][j + 1];
            a[i][j + 1] = temp;

            maxResult = max(maxResult, Check(a));

            temp = a[i][j];
            a[i][j] = a[i][j + 1];
            a[i][j + 1] = temp;
        }

        for (int j = 0; j < a.size() - 1; ++j)
        {
            char temp = a[j][i];
            a[j][i] = a[j+1][i];
            a[j+1][i] = temp;

            maxResult = max(maxResult, Check(a));

            temp = a[j][i];
            a[j][i] = a[j + 1][i];
            a[j + 1][i] = temp;
        }
    }

    cout << maxResult << '\n';
    return 0;
}

int Check(vector<string> &arr)
{
    int maxCnt = 1;
    for (int i = 0; i < arr.size(); ++i)
    {
        int cnt = 1;
        for (int j = 0; j < arr.size() - 1; ++j)
        {
            if (arr[i][j] == arr[i][j + 1])
            {
                ++cnt;
            }
            else
            {
                cnt = 1;
            }
            maxCnt = max(maxCnt, cnt);
        }

        cnt = 1;
        for (int j = 0; j < arr.size() - 1; ++j)
        {
            if (arr[j][i] == arr[j + 1][i])
            {
                ++cnt;
            }
            else
            {
                cnt = 1;
            }
            maxCnt = max(maxCnt, cnt);
        }
    }

    return maxCnt;
}