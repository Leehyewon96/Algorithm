#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> intVec;
    int num;
    for (int i = 0; i < n; ++i)
    {
        cin >> num;
        intVec.push_back(num);
    }

    stack<int> s;
    s.push(0);
    for (int i = 1; i < intVec.size(); ++i)
    {
        if (s.empty())
        {
            s.push(i);
        }
        while(!s.empty() && intVec[s.top()] < intVec[i])
        {
            intVec[s.top()] = intVec[i];
            s.pop();
        }
        s.push(i);
    }

    while(!s.empty())
    {
        intVec[s.top()] = -1;
        s.pop();
    }

    for (int i = 0; i < intVec.size(); ++i)
    {
        cout << intVec[i] << ' ';
    }
    return 0;
}