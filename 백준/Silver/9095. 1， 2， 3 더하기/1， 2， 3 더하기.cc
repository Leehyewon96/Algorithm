#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX 60

int N;
int methodNum = 0;


void DFS(int sum, int inputNum)
{
    if (sum > inputNum)
    {
        return;
    }

    if (sum == inputNum)
    {
        ++methodNum;
    }

    for (int i = 1; i <= 3; ++i)
    {
        DFS(sum + i, inputNum);
    }
}


int main()
{
    cin >> N;
    vector<int> inputVec;
    int inputNum = 0;
    for (int i = 0; i < N; ++i)
    {
        cin >> inputNum;

        DFS(0, inputNum);
        cout << methodNum << '\n';
        methodNum = 0;
    }
    return 0;
}