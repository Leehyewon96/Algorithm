#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> vec(N, 0);
    vector<int> dpVec(N, 0);

    for (int i = 0; i < N; ++i)
    {
        cin >> vec[i];
    }

    int res = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (vec[i] > vec[j])
            {
                dpVec[i] = max(dpVec[i], dpVec[j]);
            }
        }
        dpVec[i]++;
        res = max(dpVec[i], res);
    }

    cout << res;

    return 0;

}