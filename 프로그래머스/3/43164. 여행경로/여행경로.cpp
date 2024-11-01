#include <string>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>

using namespace std;

int visited[10001];
int usedCnt = 0;
int endFlag = false;

void DFS(const vector<vector<string>>& tickets, string cur, vector<string>& answer)
{
    if(usedCnt == tickets.size())
    {
        endFlag = true;
    }
    for(int i = 0; i < tickets.size(); i++)
    {
        if(!visited[i] && tickets[i][0] == cur)
        {
            visited[i] = true;
            usedCnt++;
            answer.push_back(tickets[i][1]);
            DFS(tickets, tickets[i][1], answer);
            
            if(!endFlag)
            {
                visited[i] = false;
                answer.pop_back();
            }
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    
    sort(tickets.begin(), tickets.end());
    answer.push_back("ICN");
    DFS(tickets, "ICN", answer);
    
    return answer;
}