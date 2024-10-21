#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int tired = 0;
int minTired = INT32_MAX;

bool visited[16];

void Pick(vector<map<string, int>>& tiredMap, vector<int>& picks, const vector<string>& minerals, int pickedMineral, int picked, int cur)
{
    if (picked >= picks.size())
    {
        return;
    }

    for (int i = pickedMineral; i < pickedMineral + 5; i++)
    {
        if (i >= minerals.size())
        {
            return;
        }

        tired += tiredMap[picks[picked]][minerals[i]];
    }

    
    Pick(tiredMap, picks, minerals, pickedMineral + 5, picked + 1, cur + 1);
}

void Perm(vector<map<string, int>>& tiredMap, const vector<int>& picks, vector<int>& permedPicks,const vector<string>& minerals)
{
    if (permedPicks.size() == picks.size())
    {
        tired = 0;
        Pick(tiredMap, permedPicks, minerals, 0, 0, 0);
        minTired = min(tired, minTired);
    }

    for (int i = 0; i < picks.size(); i++)
    {
        if (visited[i])
        {
            continue;
        }
        visited[i] = true;
        permedPicks.push_back(picks[i]);
        Perm(tiredMap, picks, permedPicks, minerals);
        visited[i] = false;
        permedPicks.pop_back();
    }
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;

    vector<map<string, int>> tiredMap(3);
    tiredMap[0]["diamond"] = 1;
    tiredMap[0]["iron"] = 1;
    tiredMap[0]["stone"] = 1;

    tiredMap[1]["diamond"] = 5;
    tiredMap[1]["iron"] = 1;
    tiredMap[1]["stone"] = 1;

    tiredMap[2]["diamond"] = 25;
    tiredMap[2]["iron"] = 5;
    tiredMap[2]["stone"] = 1;

    vector<int> picksVec;
    for (int i = 0; i < picks.size(); i++)
    {
        for (int j = 0; j < picks[i]; j++)
        {
            picksVec.push_back(i);
        }
    }

    /*vector<int> permedPicks;
    Perm(tiredMap, picksVec, permedPicks, minerals);*/

    do
    {
        tired = 0;
        Pick(tiredMap, picksVec, minerals, 0, 0, 0);
        minTired = min(tired, minTired);
    } 
    while (next_permutation(picksVec.begin(), picksVec.end()));

    return minTired;
}