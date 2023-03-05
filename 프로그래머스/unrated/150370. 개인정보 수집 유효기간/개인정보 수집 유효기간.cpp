#include <string>
#include <vector>
#include <sstream>

using namespace std;
vector<int> solution(string today, vector<string> terms, vector<string> privacies);
vector<string> Split(string dayStr, char delimiter);
bool IsOverDeadLine(vector<string> today, vector<string> joinDay, int deadLine);

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    vector<string> day = Split(today, '.');
    int answerSize = 1;
    for (int i = 0; i < privacies.size(); ++i)
    {
        vector<string> deadLineTemp = Split(privacies[i], ' ');
        int month = 1;
        for (int j = 0; j < terms.size(); ++j)
        {
            vector<string> deadLineType = Split(terms[j], ' ');
            if (deadLineType[0] == deadLineTemp[1])
            {
                month = stoi(deadLineType[1]);
                break;
            }
        }

        vector<string> joinDay = Split(deadLineTemp[0], '.');
        bool isOverDeadLine = IsOverDeadLine(day, joinDay, month);

        if (isOverDeadLine)
        {
            answer.push_back(i + 1);
        }
    }


    return answer;
}

vector<string> Split(string dayStr, char delimiter)
{
    vector<string> result;
    stringstream stream(dayStr);
    string resTemp;

    while (getline(stream, resTemp, delimiter))
    {
        result.push_back(resTemp);
    }

    return result;
}

// 오늘날짜와 데드라인 비교해서 지났으면 True, 안지났으면 False반환
bool IsOverDeadLine(vector<string> today, vector<string> joinDay, int deadLine)
{
    // 1. 가입날짜 + 유효기간 개월수 해서 날짜 만들기
    int joinMonth = stoi(joinDay[1]) + deadLine;

    int year = joinMonth / 12;
     if (joinMonth % 12 == 0)
        year -= 1;

    int deadLineYear = year + stoi(joinDay[0]);
    int deadLineMonth = joinMonth % 12;
    if (joinMonth % 12 == 0)
        deadLineMonth = 12;
    int deadLineDay = stoi(joinDay[2]) - 1;
    if (deadLineDay == 0)
    {
        deadLineDay = 28;
        deadLineMonth -= 1;
        if (deadLineMonth == 0)
        {
            deadLineMonth = 12;
            deadLineYear -= 1;
        }
    }

    if (stoi(today[0]) == deadLineYear) // 연도 같으면
    {
        if (stoi(today[1]) == deadLineMonth) // 월 같으면
        {
            if (stoi(today[2]) <= deadLineDay) // 일이 안지났으면 폐기안함
            {
                return false;
            }
            else //일이 지났으면 폐기함
            {
                return true;
            }
        }
        else if (stoi(today[1]) > deadLineMonth) // 오늘 날짜의 월이 더 크면 폐기함
        {
            return true;
        }
        else // 오늘 날짜의 월이 더 작으면 폐기안함
        {
            return false;
        }
    }
    else if (stoi(today[0]) > deadLineYear) // 오늘 날짜 연도가 더 크면 폐기함
    {
        return true;
    }
    else // 오늘 날짜 연도가 더 작으면 폐기안함
    {
        return false;
    }
}