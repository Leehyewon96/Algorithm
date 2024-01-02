#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    stack<char> left;
    stack<char> right;

    string str;
    cin >> str;

    for (char ch : str)
    {
        left.push(ch);
    }

    int n;
    cin >> n;

    string cmd;
    cin.ignore();
    for (int i = 0; i < n; ++i)
    {
        getline(cin, cmd);

        if (cmd.front() == 'L')
        {
            if (!left.empty())
            {
                right.push(left.top());
                left.pop();
            }
        }
        else if (cmd.front() == 'D')
        {
            if (!right.empty())
            {
                left.push(right.top());
                right.pop();
            }
        }
        else if (cmd.front() == 'B')
        {
            if (!left.empty())
            {
                left.pop();
            }
        }
        else if (cmd.front() == 'P')
        {
            left.push(cmd.back());
        }
    }

    while (!left.empty())
    {
        right.push(left.top());
        left.pop();
    }

    while (!right.empty())
    {
        cout << right.top();
        right.pop();
    }
    return 0;
}