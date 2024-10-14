#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool dp[2501][2501];
bool IsPalindrome(const string& str)
{
    int s = 0;
    int e = str.length() - 1;
    
    while(s < e)
    {
        if(str[s] != str[e])
        {
            return false;
        }
        
        s++;
        e--;
    }
    return true;
}

int solution(string s)
{
    int answer = 0;
    
    for(int i = 0; i < s.length(); i++)
    {
        dp[i][i] = true;
        answer = 1;
    }
    
    for(int i = 0; i < s.length() - 1; i++)
    {
        if(s[i] == s[i+1])
        {
            dp[i][i+1] = true;
            answer = 2;
        }
    }
    
    for(int i = 3; i <= s.length(); i++)
    {
        for(int j = 0; j + i - 1 < s.length(); j++)
        {
            int idx = j + i - 1;
            if(s[j] == s[idx] && dp[j+1][idx-1])
            {
                dp[j][idx] = true;
                answer = i;
            }
        }
    }
    
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << answer << endl;

    return answer;
}