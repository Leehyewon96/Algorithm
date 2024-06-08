#include <iostream>
#include <algorithm>
#include <tuple>
#include <string>
#include <vector>
using namespace std;

long long Calc(int N)
{
    long long len = 0;
    for (int start = 1, i = 1; start <= N; start *= 10, ++i)
    {
        int end = start * 10 - 1;
        if (end > N)
        {
            end = N;
        }

        len += (long long)(end - start + 1) * i;
    }
    return len;
}

int BinarySearch(int left, int right, int targetLen)
{
    if (left >= right)
    {
        return right;
    }

    int mid = (left + right) / 2;
    long long midLen = Calc(mid);

    if (midLen < targetLen)
    {
        return BinarySearch(mid + 1, right, targetLen);
    }
    else
    {
        return BinarySearch(left, mid, targetLen);
    }
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, K;
    cin >> N >> K;

    if (Calc(N) < K)
    {
        cout << -1;
        return 0;
    }

    int num = BinarySearch(1, N, K);
    long long ans = Calc(num - 1);
    

    string str = to_string(num);
    cout << str[K - ans - 1];
    
    
    return 0;
}