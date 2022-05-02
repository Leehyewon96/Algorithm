#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int findFunc(string str, string sfind);

int main()
{
    int N;
    cin >> N;
    stack<int> s;

    for(int i = 0; i < N; i++)
    {
        string order;
        cin >> order;
        if(order == "pop")
        {
            if(s.empty() == 0)
            {
                cout << s.top() << endl;
                s.pop();
            }
            else
            {
                cout << "-1" << endl;
            }
        }
        else if(order == "size")
        {
           cout << s.size() << endl;
        }
        else if(order == "empty")
        {
            cout << s.empty() << endl;
        }
        else if(order == "top")
        {
            if(s.empty() == 0)
                cout << s.top() << endl;
            else
            cout << "-1" << endl;
        }
        else
        {
            int num;
            cin >> num;
            s.push(num);
        }
    }

    return 0;
}