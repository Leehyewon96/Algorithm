#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


long long BinarySearch(const vector<long long>& houseVec, long long left, long long right, long long targetCnt)
{
    if (left > right)
    {
        return right;
    }

    long long mid = (left + right) / 2;
    
    //mid보다 간격 크거나 같은 집 개수 세기
    long long cnt = 1;
    int preHouse = houseVec.front();
    for (int i = 1; i < houseVec.size(); ++i)
    {
        if (houseVec[i] - preHouse >= mid) 
        {
            cnt++;
            preHouse = houseVec[i];
        }
    }

    if (cnt >= targetCnt) //놓을 수 있는 개수가 targetCnt 이상이면 간격 더 증가시켜서 다시 검사
    {
        return BinarySearch(houseVec, mid + 1, right, targetCnt);
    }
    else //개수가 부족하면 간격 줄여서 다시 검사
    {
        return BinarySearch(houseVec, left, mid - 1, targetCnt);
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, C;
    cin >> N >> C;

    vector<long long> houseVec(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> houseVec[i];
    }

    sort(houseVec.begin(), houseVec.end());
    int maxInterval = houseVec.back() - houseVec.front();
    cout << BinarySearch(houseVec, 1, maxInterval, C);

    return 0;
}