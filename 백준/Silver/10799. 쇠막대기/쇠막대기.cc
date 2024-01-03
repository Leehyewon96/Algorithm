#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    string str;
    cin >> str;

    stack<int> s;
    bool isRazer = false;
    int answer = 0;
    for (int i = 0; i < str.length(); ++i)
    {
        if (str[i] == '(')
        {
            s.push(i + 1);
        }
        else
        {
            
            if (!s.empty())
            {
                if (i == s.top())
                {
                    s.pop();
                    answer += s.size();
                }
                else
                {
                    ++answer;
                    s.pop();
                }
            }
            
        }
    }

    cout << answer;
    return 0;
}