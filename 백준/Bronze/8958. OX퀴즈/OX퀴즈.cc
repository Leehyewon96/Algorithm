#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N, cnt = 0, score = 0;
    string s;
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> s;

        for(int k = 0; k <= s.length(); k++)
        {
            if(s[k] == 'O')
            {
                cnt++;
            }
            else
            {
                for(int m = 1; m <= cnt; m++)
                {
                    score += m;
                }
                cnt = 0;
            }
        }
        cout << score << endl;
        score = 0;
    }

    return 0;
}