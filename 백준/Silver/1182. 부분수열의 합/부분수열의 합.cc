#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int ans = 0;
int N, S;

void Pick(vector<int> &vec, int cur, int sum)
{
    if (N == cur)
    {
        return;
    }

    if (sum + vec[cur] == S)
    {
        ans += 1;
        //return;
    }

    Pick(vec, cur + 1, sum);
    Pick(vec, cur + 1, sum + vec[cur]);
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    
    cin >> N >> S;
    vector<int> vec;
    int num;
    for (int i = 0; i < N; ++i)
    {
        cin >> num;
        vec.push_back(num);
    }

    Pick(vec, 0, 0);

    cout << ans;
}