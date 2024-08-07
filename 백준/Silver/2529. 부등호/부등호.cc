#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
#include <memory.h>

using namespace std;

vector<char> signVec;
int N = 0;
string curMax = "0";
string curMin = "9999999999";

int visited[11];

void Solution(string v)
{
    if (v.size() == N + 1)
    {
        curMax = max(curMax, v);
        curMin = min(curMin, v);
        return;
    }

    for (int i = 0; i < 10; ++i)
    {
        if (visited[i])
        {
            continue;
        }

        if (v.size() != 0)
        {
            if (signVec[v.size() - 1] == '<')
            {
                if (v.back() > i + '0')
                {
                    continue;
                }
            }

            if (signVec[v.size() - 1] == '>')
            {
                if (v.back() < i + '0')
                {
                    continue;
                }
            }
        }

        visited[i] = true;
        v.push_back(i + '0');
        Solution(v);
        visited[i] = false;
        v.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    std::cout.tie(NULL);
    cin.tie(NULL);

    cin >> N;
    
    char sign;
    for (int i = 0; i < N; ++i)
    {
        cin >> sign;
        signVec.push_back(sign);
    }

    string v = "";
    Solution(v);
    
    cout << curMax << '\n' << curMin;
    return 0;
}