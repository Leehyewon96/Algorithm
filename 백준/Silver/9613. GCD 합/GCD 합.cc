#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

long SumOfGCD(vector<int> s);
long GCD(int m, int n);

int main()
{
    int n = 0;
    cin >> n;
    vector<long> answer;
    for (int i = 0; i < n; ++i)
    {
        vector<int> s;
        int m = 0;
        cin >> m;
        int input;
        for (int j = 0; j < m; ++j)
        {
            cin >> input;
            s.push_back(input);
        }
        answer.push_back(SumOfGCD(s));
    }

    for (int i = 0; i < answer.size(); ++i)
    {
        cout << answer[i] << '\n';
    }
    return 0;
}

long SumOfGCD(vector<int> s)
{
    long sum = 0;
    int curNum;
    int idx = s.size() - 1;
    while (idx != -1)
    {
        curNum = s[idx];
        for (int i = 0; i < idx; ++i)
        {
            sum += GCD(curNum, s[i]);
            
        }
        --idx;
    }

    return sum;
}

long GCD(int m, int n)
{
    while (n != 0)
    {
        int last = m % n;
        m = n;
        n = last;
    }

    return m;
}