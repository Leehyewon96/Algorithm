#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int GCD(vector<int> vec);
int SubGCD(int m, int n);


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, s;
    cin >> n >> s;
    
    vector<int> diffVec;
    int input;
    int diff;
    for (int i = 0; i < n; ++i)
    {
        cin >> input;
        diff = (s > input) ?  s - input : input - s;
        diffVec.push_back(diff);
    }

    cout << GCD(diffVec) << '\n';

    return 0;
}

int GCD(vector<int> vec)
{
    int i = vec.size() - 1;
    int distance = vec[i];
    int answer = distance;
    while (i != -1)
    {
        answer = SubGCD(answer, vec[i]);
        --i;
    }

    return answer;
}

int SubGCD(int m, int n)
{
    int last;
    while (n != 0)
    {
        last = m % n;
        m = n;
        n = last;
    }

    return m;
}