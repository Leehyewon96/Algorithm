#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

bool a[1001][1001] = {false, };
bool check[1001] = { false, };
bool check2[1001] = { false, };

void DFS(int num, int n)
{
    check[num] = true;
    cout << num << ' ';
    for (int i = 1; i <= n; ++i)
    {
        if (a[num][i] == true && check[i] == false)
        {
            DFS(i, n);
        }
    }
}

void BFS(int num, int n)
{
    queue<int> q;
    check2[num] = true;
    q.push(num);
    cout << num << ' ';
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        for (int i = 1; i <= n; ++i)
        {
            if (a[temp][i] == true && check2[i] == false)
            {
                cout << i << ' ';
                check2[i] = true;
                q.push(i);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, V;

    cin >> N >> M >> V;

    for (int i = 0; i < M; ++i)
    {
        int v1, v2;
        cin >> v1 >> v2;
        a[v1][v2] = true;
        a[v2][v1] = true;
    }

    DFS(V, N);
    cout << '\n';
    BFS(V, N);
    return 0;
}