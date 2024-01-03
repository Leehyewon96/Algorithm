#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    string str;
    getline(cin, str);

    stack<char> s;
    bool isprint = false;
    for (char ch : str)
    {
        if (ch == '>')
        {
            cout << ch;
            isprint = false;
        }
        else if (ch == '<')
        {
            while (!s.empty())
            {
                cout << s.top();
                s.pop();
            }
            isprint = true;
        }
        else if(!isprint)
        {
            if (ch != ' ')
            {
                s.push(ch);
            }
            else
            {
                while (!s.empty())
                {
                    cout << s.top();
                    s.pop();
                }
                cout << ' ';
            }
        }

        if (isprint)
        {
            cout << ch;
        }
    }
    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }
    return 0;
}