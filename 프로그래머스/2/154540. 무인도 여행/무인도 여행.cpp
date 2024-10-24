#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int ud[4] = { -1, 1, 0, 0};
int rl[4] = {0, 0, -1, 1};

bool visited[101][101];

int BFS(const vector<string>& maps, int sr, int sc)
{
    int total = 0;
    queue<pair<int, int>> q;
    q.push({sr, sc});
    
    while(!q.empty())
    {
        pair<int, int> front = q.front();
        q.pop();
        total += maps[front.first][front.second] - '0';
        for(int i = 0; i < 4; i++)
        {
            int nr = front.first + ud[i];
            int nc = front.second + rl[i];
            
            if(nr < 0 || nr >= maps.size() || nc < 0 || nc >= maps[0].size())
            {
                continue;
            }
            
            if(visited[nr][nc])
            {
                continue;
            }
            
            if(maps[nr][nc] == 'X')
            {
                continue;
            }
            
            visited[nr][nc] = true;
            q.push({nr, nc});
        }
    }
    
    return total;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    for(int i = 0; i < maps.size(); i++)
    {
        for(int j = 0; j < maps[0].size(); j++)
        {
            if(maps[i][j] == 'X')
            {
                continue;
            }
            
            if(visited[i][j])
            {
                continue;
            }
            
            visited[i][j] = true;
            int day = BFS(maps, i, j);
            answer.push_back(day);
        }
    }
    
    
    if(answer.size() == 0)
    {
        answer.push_back(-1);
    }
    else
    {
        sort(answer.begin(), answer.end());
    }
    return answer;
}