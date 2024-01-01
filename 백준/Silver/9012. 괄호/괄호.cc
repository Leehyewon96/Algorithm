#include <iostream>
#include <string>

using namespace std;


int main()
{
    string str;
    int T;
    int cnt1 = 0, cnt2 = 0;
    cin >> T;
    cin.ignore();

    while(T--)
    {
        getline(cin, str);

        for(int i = 0; i < str.length(); i++)
        {
            if(str[i] == '(')
            {
                cnt1++;
            }
            else
            {
                cnt2++;
            }
            if(cnt1 < cnt2)
            {
                break;
            }
        }
        if(cnt1 == cnt2)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
        cnt1 = 0;
        cnt2 = 0;
    }
    
    return 0;
}