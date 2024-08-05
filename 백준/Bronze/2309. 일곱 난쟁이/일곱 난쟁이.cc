#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    vector<int> vec;
    int sum = 0;
    for (int i = 0; i < 9; ++i)
    {
        cin >> N;
        vec.push_back(N);
        sum += N;
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < vec.size() - 1; ++i)
    {
        for (int j = i + 1; j < vec.size(); ++j)
        {
            if ((sum - (vec[j] + vec[i])) == 100)
            {
                for (int l = 0; l < vec.size(); ++l)
                {
                    if (l != i && l != j)
                    {
                        cout << vec[l] << '\n';

                    }
                }

                return 0;
            }
        }
    }
    return 0;
}