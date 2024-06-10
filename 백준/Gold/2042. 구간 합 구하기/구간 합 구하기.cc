#include <iostream>
#include <vector>
#include <map>
using namespace std;

void UpdateFenwick(vector<long long>& fenVec, int index, long long diff)
{
    while (index <= fenVec.size() - 1)
    {
        fenVec[index] += diff;
        index += (index & -index);
    }
}

void MakeFenwick(vector<long long>& fenVec, vector<long long>& numVec)
{
    for (int i = 1; i <= fenVec.size() - 1; ++i)
    {
        UpdateFenwick(fenVec, i, numVec[i]);
    }
}

long long Sum(const vector<long long>& fenVec, int index)
{
    long long ans = 0;
    while (index > 0)
    {
        ans += fenVec[index];
        index -= (index & -index);
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M, K;
    cin >> N >> M >> K;

    vector<long long> numVec(N + 1);
    vector<long long> fenVec(N + 1);
    for (int i = 1; i <= N; ++i)
    {
        cin >> numVec[i];
    }

    MakeFenwick(fenVec, numVec);

    int turn = M + K;
    long long type, a, b;
    for (int i = 0; i < turn; ++i)
    {
        cin >> type >> a >> b;

        if (type == 1)
        {
            long long diff = b - numVec[a];
            numVec[a] = b;
            UpdateFenwick(fenVec, a, diff);
        }
        else
        {
            cout << Sum(fenVec, b) - Sum(fenVec, a - 1) << '\n';
        }
    }
    return 0;
}