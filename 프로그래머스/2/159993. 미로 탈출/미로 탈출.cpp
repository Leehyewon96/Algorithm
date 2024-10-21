#include <string>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

int visited[101][101];

int ud[4] = { -1, 1, 0, 0 };
int rl[4] = { 0, 0, -1, 1 };

int BFS(const vector<string>& maps, int sr, int sc, int er, int ec)
{
    queue<pair<int, int>> q;
    q.push({ sr, sc });
    visited[sr][sc] = true;
    int answer = 0;

    while (!q.empty())
    {
        pair<int, int> front = q.front();
        q.pop();
        if (front.first == er && front.second == ec)
        {
            return visited[front.first][front.second];
        }

        for (int i = 0; i < 4; i++)
        {
            int nr = front.first + ud[i];
            int nc = front.second + rl[i];

            if (nr < 0 || nr >= maps.size() || nc < 0 || nc >= maps[0].size())
            {
                continue;
            }

            if (visited[nr][nc] > 0)
            {
                continue;
            }

            if (maps[nr][nc] == 'X')
            {
                continue;
            }

            visited[nr][nc] = visited[front.first][front.second] + 1;

            q.push({ nr, nc });
        }
    }

    return -1;
}

int solution(vector<string> maps) {
    int answer = 0;

    pair<int, int> s;
    pair<int, int> e;
    pair<int, int> l;

    for (int i = 0; i < maps.size(); i++)
    {
        for (int j = 0; j < maps[i].size(); j++)
        {
            if (maps[i][j] == 'S')
            {
                s = { i, j };
            }
            else if (maps[i][j] == 'E')
            {
                e = { i, j };
            }
            else if (maps[i][j] == 'L')
            {
                l = { i, j };
            }
        }
    }

    int answer1 = BFS(maps, s.first, s.second, l.first, l.second);
    memset(visited, 0, sizeof(visited));
    int answer2 = BFS(maps, l.first, l.second, e.first, e.second);
    if (answer1 == -1 || answer2 == -1)
    {
        return -1;
    }
    answer = answer1 + answer2 - 2;
    return answer;
}