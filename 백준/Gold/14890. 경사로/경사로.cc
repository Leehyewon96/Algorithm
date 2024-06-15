#include <iostream>
#include <map>
#include <algorithm>

using namespace std;


int N, L;

int Solution(const int ar[101][101])
{
    int ans = 0;

    for (int i = 0; i < N; ++i)
    {
        int sameCnt = 1;
        int t = 0;
        for (int j = 0; j < N - 1; ++j)
        {
            if (ar[i][j] == ar[i][j + 1])
            {
                sameCnt++;
            }
            else if (ar[i][j] + 1 == ar[i][j + 1])
            {
                if (sameCnt >= L)
                {
                    sameCnt = 1;
                }
                else
                {
                    break;
                }
            }
            else  if (ar[i][j] == ar[i][j + 1] + 1)
            {
                if (sameCnt >= 0)
                {
                    sameCnt = -L + 1;
                }
                else
                {
                    break;
                }
            }
            else
            {
                break;
            }

            t++;
        }

        if (t == N - 1 && sameCnt >= 0)
        {
            ans++;
        }
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    cin >> N >> L;

    int arr[101][101];
    int arr2[101][101];

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> arr[i][j];

            arr2[j][i] = arr[i][j];
        }
    }


    cout << Solution(arr) + Solution(arr2);

    return 0;
}