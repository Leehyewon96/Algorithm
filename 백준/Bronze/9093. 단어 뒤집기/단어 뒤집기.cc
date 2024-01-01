#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    int T, i = 0;
    stack<char> s;
    string str;
    cin >> T;
    cin.ignore();

    for(int cnt = 0; cnt < T; cnt++)
    {
        getline(cin, str);
        str += ' ';

        for(int k = 0; k < str.length(); k++)
        {
            if(str[k] == ' ')
            {
                while(!s.empty())
                {
                    cout << s.top();
                    s.pop();
                }
                cout << " ";
            }
            else
            {
                s.push(str[k]);
            }
        }
        cout << "\n";
    }
    return 0;
}