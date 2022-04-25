#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string str;
    string alphabet = "abcdefghijklmnopqrstuvwxyz";

    cin >> str;

    int array[36] = {0, };
    
    for(int i = 0; i < (int)alphabet.length(); i++)
    {
        alphabet[i] = toupper(alphabet[i]);
        for(int j = 0; j < (int)str.length(); j++)
        {
            str[j] = toupper(str[j]);
            if(alphabet[i] == str[j])
            {
                array[i]++;
            }
        }
    }

    char max;
    int cnt = 0;
    for(int i = 0; i < 36; i++)
    {
        if(*max_element(array, array+36) == array[i])
        {
            max = alphabet[i];
            cnt++;
        }
    }
    if(cnt == 1)
    {
        cout << max << "\n";
    }
    else
    {
        cout << "?" << "\n";
    }

    return 0;
}