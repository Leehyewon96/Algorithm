#include <iostream>
using namespace std;

int main()
{
    string str;
    int cnt = 0;

    cin >> str;

    for(int i = 0; i < str.length(); i++)
    {
        cnt++;
        if(str[i] == 'c')
        {
            if(str[i+1] == '=' || str[i+1] == '-')
            {
                cnt--;
            }
        }
        else if(str[i] == 'd')
        {
            if(str[i+1] == 'z' && str[i+2] == '=')
            {
                cnt -= 2;
            }
            else if(str[i+1] == '-')
            {
                cnt--;
            }
        }
        else if(str[i] == 'l' && str[i+1] == 'j')
        {
            cnt--;
        }
        else if(str[i] == 'n' && str[i+1] == 'j')
        {
            cnt--;
        }
        else if(str[i] == 's' && str[i+1] == '=')
        {
            cnt--;
        }
        else if(str[i] == 'z' && str[i+1] == '=')
        {
            if(str[i-1] != 'd')
            {
                cnt--;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}