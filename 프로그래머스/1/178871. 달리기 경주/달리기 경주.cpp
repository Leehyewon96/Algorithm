#include <string>
#include <vector>
#include <map>

using namespace std;

void Swap(vector<string>& strVec, int a, int b)
{
    string temp = strVec[a];
    strVec[a] = strVec[b];
    strVec[b] = temp;
}

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string>& answer = players;
    
    map<string, int> playersMap;
    for(int i = 0; i < players.size(); i++)
    {
        playersMap[players[i]] = i;
    }
    
    for(int i = 0; i < callings.size(); i++)
    {
        int curPlayer = playersMap[callings[i]];
        int targetPlayer = curPlayer - 1;
        
        Swap(answer, curPlayer, targetPlayer);
        playersMap[players[curPlayer]] = curPlayer;
        playersMap[players[targetPlayer]] = targetPlayer;
    }
    
    return answer;
}