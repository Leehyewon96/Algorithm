#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int T, R;
    string S;
    cin >> T;

    for(int i = 0; i < T; i++)
    {
        cin >> R >> S;

        for(int j = 0; j < S.length(); j++)
        {
            for(int k = 0; k < R; k++)
            {
                cout << S[j];
            }
        }
        cout << "\n";
    }

    return 0;
}