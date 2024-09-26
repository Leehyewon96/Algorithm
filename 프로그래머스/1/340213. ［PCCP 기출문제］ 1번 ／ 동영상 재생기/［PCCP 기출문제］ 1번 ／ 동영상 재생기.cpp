#include <string>
#include <vector>

using namespace std;

void Next(string& pos, const string& video_len)
{
    string min = pos.substr(0, 2);
    string sec = pos.substr(3, 2);

    int imin = stoi(min);
    int isec = stoi(sec);

    isec += 10;

    if (isec > 59)
    {
        isec -= 60;
        imin += 1;
    }

    min = to_string(imin);
    sec = to_string(isec);

    if (imin == 0 || imin / 10 == 0)
    {
        min = "0" + min;
    }

    if (isec == 0 || isec / 10 == 0)
    {
        sec = "0" + sec;
    }

    pos = min + ":" + sec;
    if (video_len < pos)
    {
        pos = video_len;
    }
}

void Prev(string& pos)
{
    string min = pos.substr(0, 2);
    string sec = pos.substr(3, 2);

    int imin = stoi(min);
    int isec = stoi(sec);

    isec -= 10;

    if (isec < 0)
    {
        isec = 60 + isec;
        imin -= 1;
    }
    min = to_string(imin);
    sec = to_string(isec);

    if (imin == 0 || imin / 10 == 0)
    {
        min = "0" + min;
    }

    if (isec == 0 || isec / 10 == 0)
    {
        sec = "0" + sec;
    }

    pos = min + ":" + sec;
    if (imin < 0)
    {
        pos = "00:00";
    }
}

void CheckOp(string& pos, const string& op_start, const string& op_end)
{
    if (op_start <= pos && op_end >= pos)
    {
        pos = op_end;
    }
}


string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    answer = pos;
    for (int i = 0; i < commands.size(); ++i)
    {
        CheckOp(answer, op_start, op_end);

        if (commands[i] == "next")
        {
            Next(answer, video_len);
        }
        else if (commands[i] == "prev")
        {
            Prev(answer);
        }
    }
    CheckOp(answer, op_start, op_end);

    return answer;
}