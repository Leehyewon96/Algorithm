#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int ans = 0;

bool visited[9];

void Perm(const vector<string>& data, const string& str, string& s)
{
    if (s.length() == 8)
    {
        bool isValid = true;
        for (int i = 0; i < data.size(); ++i)
        {
            int first = find(s.begin(), s.end(), data[i][0]) - s.begin();
            int second = find(s.begin(), s.end(), data[i][2]) - s.begin();

            int diff = abs(first - second) - 1;

            if (data[i][3] == '=')
            {
                if (diff != data[i].back() - '0')
                {
                    isValid = false;
                    break;
                }
            }
            else if (data[i][3] == '<')
            {
                if (diff >= data[i].back() - '0')
                {
                    isValid = false;
                    break;
                }
            }
            else if (data[i][3] == '>')
            {
                if (diff <= data[i].back() - '0')
                {
                    isValid = false;
                    break;
                }
            }
        }
        if (isValid)
        {
            ++ans;
        }
        return;
    }

    for (int i = 0; i < 8; ++i)
    {
        if (visited[i])
        {
            continue;
        }
        visited[i] = true;
        s.push_back(str[i]);
        Perm(data, str, s);
        s.pop_back();
        visited[i] = false;
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    ans = 0;
    string str = "ACFJMNRT";
    string s;
    Perm(data, str, s);


    answer = ans;
    return answer;
}