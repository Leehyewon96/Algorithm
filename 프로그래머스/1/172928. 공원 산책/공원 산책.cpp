#include <string>
#include <vector>

using namespace std;

int ud[4] = {-1, 1, 0, 0};
int rl[4] = {0, 0, -1, 1};

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    pair<int, int> cur;
    for(int i = 0; i < park.size(); ++i)
    {
        for(int j = 0; j < park[0].size(); ++j)
        {
            if(park[i][j] == 'S')
            {
                cur = {i, j};
            }
        }
    }
    
    for(int i = 0; i < routes.size(); i++)
    {
        char dir = routes[i][0];
        int cnt = routes[i][2] - '1' + 1;
        
        int moveIdx = 0;
        
        if(dir == 'N')
        {
            moveIdx = 0;
        }
        else if(dir == 'S')
        {
            moveIdx = 1;
        }
        else if(dir == 'W')
        {
            moveIdx = 2;
        }
        else if(dir == 'E')
        {
            moveIdx = 3;
        }
        
        pair<int, int> nextPoint;
        nextPoint = cur;
        bool able = true;
        for(int j = 0; j < cnt; j++)
        {
            int nx = nextPoint.first + ud[moveIdx];
            int ny = nextPoint.second + rl[moveIdx];
            
            if(nx < 0 || nx >= park.size() || ny < 0 || ny >= park[0].size())
            {
                able = false;
                break;
            }
            
            if(park[nx][ny] == 'X')
            {
                able = false;
                break;
            }
            
            nextPoint = {nx, ny};
        }
        
        if(able)
        {
            cur = nextPoint;
        }
    }
    
    answer.push_back(cur.first);
    answer.push_back(cur.second);
    
    return answer;
}