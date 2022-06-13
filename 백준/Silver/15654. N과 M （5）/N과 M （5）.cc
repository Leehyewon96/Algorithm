#include <iostream>
#include <algorithm>
using namespace std;

void dfs(int k);

int arr[9];
bool visited[9] = {0};
int answer[9];

int N, M;

int main()
{
    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    dfs(0);

    return 0;
}

void dfs(int k)
{
    if(k == M)
    {
        for(int i = 0; i < k; i++)
        {
            cout << answer[i] << ' ';
        }
        cout << "\n";
    }
    else
    {
        for(int i = 0; i < N; i++)
        {
            if(!visited[i])
            {
                visited[i] = true;
                answer[k] = arr[i];
                dfs(k+1);
                visited[i] = false;
            } 
        }
    }
}
