#include <iostream>
#include <vector>
using namespace std;

long long  BinarySearch(const vector<long long >& lenVec, long long  left, long long  right, long long targetLen)
{
    if (left > right)
    {
        return right;
    }

    long long mid = (left + right) / 2;
    
    long long  cuttingLen = 0;
    for (int i = 0; i < lenVec.size(); ++i)
    {
        cuttingLen += lenVec[i] > mid ? lenVec[i] - mid : 0;
    }

    if (cuttingLen < targetLen)
    {
        return BinarySearch(lenVec, left, mid - 1, targetLen);
    }
    else
    {
        return BinarySearch(lenVec, mid + 1, right, targetLen);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<long long > lenVec(N);
    long long maxLen = 0;
    for (int i = 0; i < N; ++i)
    {
        cin >> lenVec[i];
        maxLen = max(maxLen, lenVec[i]);
    }

    cout << BinarySearch(lenVec, 0, maxLen , M);

    return 0;
}