#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int arr[500002] = { 0, };
bool broken[11] = { false, };

int Possible(int c)
{
    if (c == 0)
    {
        if (broken[0])
        {
            return 0;
        }
        else {
            return 1;
        }
    }

    int pushNum = 0;
    while (c > 0)
    {
        int last = c % 10;
        if (broken[last])
        {
            return 0;
        }

        ++pushNum;
        c /= 10;
    }

    return pushNum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int channel, brokenNum, num;
    cin >> channel;
    cin >> brokenNum;
    for (int i = 0; i < brokenNum; ++i)
    {
        cin >> num;
        broken[num] = true;
    }

    int curChannel = 100;
    int ans = channel - curChannel;
    if (ans < 0)
    {
        ans *= -1;
    }
    for (int i = 0; i <= 1000000; ++i)
    {
        int cnt = Possible(i);
        if (cnt > 0)
        {
            int press = i - channel;
            if (press < 0)
            {
                press *= -1;
            }

            if (ans > cnt + press)
            {
                ans = cnt + press;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}