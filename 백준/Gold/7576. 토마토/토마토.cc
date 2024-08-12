#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;
int N, M;
int fruit[1001][1001];
bool visited[1001][1001];

int rl[4] = {1, 0, 0, -1};
int ud[4] = {0, 1, -1, 0};
queue<pair<int, int>> q;

void BFS()
{
    while (!q.empty())
    {
        pair<int, int> front = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int newCol = front.first + ud[i];
            int newRow = front.second + rl[i];

            if (newCol < 1 || newCol > M || newRow < 1 || newRow > N)
            {
                continue;
            }

            if (fruit[newCol][newRow] == 0 && !visited[newCol][newRow])
            {
                visited[newCol][newRow] = true;
                q.push(make_pair(newCol, newRow));
                fruit[newCol][newRow] = fruit[front.first][front.second] + 1;
            }
        }
    }
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    cin >> N >> M;

    int notRipened = 0;
    for (int i = 1; i <= M; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            cin >> fruit[i][j];
            if (fruit[i][j] == 1)
            {
                q.push(make_pair(i, j));
            }
        }
    }

    BFS();

    int res = 0;
    for (int i = 1; i <= M; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            if (fruit[i][j] == 0)
            {
                cout << "-1\n";
                return 0;
            }
            

            res = max(res, fruit[i][j]);
        }
    }

    cout << --res << '\n';
    return 0;
}