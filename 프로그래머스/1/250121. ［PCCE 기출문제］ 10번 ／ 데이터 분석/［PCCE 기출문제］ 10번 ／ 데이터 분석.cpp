#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<string, int> extMap;

int curExt = 0;

bool Comp(vector<int>& a, vector<int>& b)
{
    return a[curExt] < b[curExt];
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    
    extMap["code"] = 0;
    extMap["date"] = 1;
    extMap["maximum"] = 2;
    extMap["remain"] = 3;
    
    
    curExt = extMap[ext];
    for(int i = 0; i < data.size(); ++i)
    {
        if(data[i][curExt] < val_ext)
        {
            answer.push_back(data[i]);
        }
    }
    curExt = extMap[sort_by];
    sort(answer.begin(), answer.end(), Comp);
    
    return answer;
}