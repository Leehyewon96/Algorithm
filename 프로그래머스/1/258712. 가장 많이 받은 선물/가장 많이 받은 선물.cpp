#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

vector<string> GetString(string str)
{
    vector<string> resVec;
    istringstream res(str);
    char separator = ' ';
    string buffer = "";
    while (getline(res, buffer, separator))
    {
        resVec.push_back(buffer);
    }

    return resVec;
}
int solution(vector<string> friends, vector<string> gifts) 
{
    int answer = 0;

    map<string, int> fm;
    for (int i = 0; i < friends.size(); ++i)
    {
        fm.insert({ friends[i], i });
    }

    vector<vector<int>> pVec(friends.size(), vector<int>(friends.size(), 0));
    vector<int> giftScore(friends.size(), 0);
    for (int i = 0; i < gifts.size(); ++i)
    {
        vector<string> fStr = GetString(gifts[i]);
        pVec[fm[fStr[0]]][fm[fStr[1]]]++;
        giftScore[fm[fStr[0]]]++;
        giftScore[fm[fStr[1]]]--;
    }

    int maxNum = 0;
    vector<int> giftVec(friends.size(), 0);
    for (int i = 0; i < friends.size() - 1; ++i)
    {
        for (int j = i+1; j < pVec[i].size(); ++j)
        {
            if (pVec[i][j] > pVec[j][i])
            {
                giftVec[i]++;
            }
            else if(pVec[i][j] < pVec[j][i])
            {
                giftVec[j]++;
            }
            else
            {
                if (giftScore[i] > giftScore[j])
                {
                    giftVec[i]++;
                }
                else if (giftScore[i] < giftScore[j])
                {
                    giftVec[j]++;
                }
            }

            maxNum = max(max(giftVec[i], giftVec[j]), maxNum);
        }
    }

    return maxNum;
}