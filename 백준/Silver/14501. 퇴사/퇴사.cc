#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX 16

int N;
int T[MAX];
int P[MAX];
int maxSum = 0;

void DFS(int day, int sum)
{
    if (day >= N)
    {
        maxSum = max(maxSum, sum);
        return;
    }

    if (day + 1 <= N)
    {
        DFS(day + 1, sum);
    }

    if (day + T[day] <= N)
    {
        DFS(day + T[day], sum + P[day]);
    }
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> T[i] >> P[i];
    }
    DFS(0, 0);
    
    cout << maxSum << '\n';
    return 0;
}