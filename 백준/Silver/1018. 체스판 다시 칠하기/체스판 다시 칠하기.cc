#include <iostream>
using namespace std;

int main()
{
    char arr[8][8] = {'W', 'B', 'W', 'B', 'W', 'B','W', 'B',
                      'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
                      'W', 'B', 'W', 'B','W', 'B', 'W', 'B',
                      'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
                      'W', 'B', 'W', 'B', 'W', 'B','W', 'B',
                      'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
                      'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
                      'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W' };

    char arr2[8][8] = { 'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
                      'W', 'B', 'W', 'B','W', 'B', 'W', 'B',
                      'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
                      'W', 'B', 'W', 'B', 'W', 'B','W', 'B',
                      'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
                      'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
                      'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
                      'W', 'B', 'W', 'B', 'W', 'B','W', 'B' };

    char input[50][50];
    int N, M, cnt = 0, min = 6400;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> input[i][j];
        }
    }
    
    int k = 0, l = 0;

    for (int k = 0; k < N - 7; k++)
    {
        for (l = 0; l < M - 7; l++)
        {
            for (int i = k; i < k + 8; i++)
            {
                for (int j = l; j < l + 8; j++)
                {
                    if (input[i][j] != arr[i - k][j - l])
                    {
                        cnt++;
                    }
                }
            }

            if (min > cnt)
            {
                min = cnt;
            }
            cnt = 0;

            for (int i = k; i < k + 8; i++)
            {
                for (int j = l; j < l + 8; j++)
                {
                    if (input[i][j] != arr2[i - k][j - l])
                    {
                        cnt++;
                    }
                }
            }

            if (min > cnt)
            {
                min = cnt;
            }
            cnt = 0;
        }
    }

    cout << min << endl;
    return 0;
}