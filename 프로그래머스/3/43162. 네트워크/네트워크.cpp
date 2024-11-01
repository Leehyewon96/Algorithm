#include <string>
#include <vector>

using namespace std;

int visited[201];

void DFS(int cur, const vector<vector<int>>& computers)
{
    for(int i = 0; i < computers.size(); i++)
    {
        if(visited[i])
        {
            continue;
        }
        
        if(computers[cur][i] == 0)
        {
            continue;
        }
        
        visited[i] = true;
        
        DFS(i, computers);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i = 0; i < n; i++)
    {
        if(visited[i])
        {
            continue;
        }
        
        visited[i] = true;
        answer++;
        DFS(i, computers);
    }
    
    return answer;
}