#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Input
{
    int mass = -1;
    int value = -1;
    int isBag = -1;

    Input(int m, int v, int bag) : mass(m), value(v), isBag(bag) {}
};

bool Cmp(Input a, Input b)
{
    return (a.mass < b.mass) || (a.mass == b.mass && a.value > b.value);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<Input> inputVec;

    int m, v;
    for (int i = 0; i < N; ++i)
    {
        cin >> m >> v;
        Input input(m,v,0);
        inputVec.push_back(input);
    }

    int bagMass;
    for (int i = 0; i < K; ++i)
    {
        cin >> bagMass;
        Input input(bagMass, 0, 1);
        inputVec.push_back(input);
    }

    sort(inputVec.begin(), inputVec.end(), Cmp);

    priority_queue<int> pq;
    long long ans = 0;
    for (int i = 0; i < inputVec.size(); ++i)
    {
        if(!inputVec[i].isBag) // 보석이면 큐에 넣기
        {
            pq.push(inputVec[i].value);
            
        }
        else
        {
            if (!pq.empty())
            {
                ans += pq.top();
                pq.pop();
            }
        }
    }

    cout << ans << '\n';

    return 0;
}