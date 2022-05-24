#include <iostream>
using namespace std;

int N, M;
int arr[9];
bool visited[9];

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
            if (visited[i] == false)
            {
                arr[k] = i;
                visited[i] = true;
                dfs(k+1);
                visited[i] = false;
            }
        }
    }
}