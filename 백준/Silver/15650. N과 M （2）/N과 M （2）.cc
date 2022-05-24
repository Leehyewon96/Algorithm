#include <iostream>
using namespace std;

int N, M;
int arr[9];

void dfs(int k);

void Init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
};

int main()
{
    Init();
    cin >> N >> M;

    dfs(0);

    return 0;
}

void dfs(int k)
{
    if (k == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << "\n";
    }
    else
    {
        for (int i = 1; i <= N; i++)
        {
            if (k == 0)
            {
                arr[k] = i;
                dfs(k + 1);
                continue;
            }
            if (arr[k - 1] < i)
            {
                arr[k] = i;
                dfs(k + 1);
            }
        }
    }
}