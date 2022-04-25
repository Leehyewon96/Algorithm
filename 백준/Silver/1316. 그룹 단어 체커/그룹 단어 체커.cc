#include <iostream>
using namespace std;

int main()
{
    int cnt = 0;
    int count = 0;
    int N;
    cin >> N;

    for(int l = 0; l < N; l++)
    {
        string str;
        cin >> str;


        for(int i = 0; i < str.length(); i++)
        {
            for(int j = i + 1; j < str.length(); j++)
            {
                if(str[i] == str[j] && str[i] != str[j-1])
                {
                    cnt++;
                }
            }
        }

        if(cnt == 0)
        {
            count++;
        }

        cnt = 0;

    }

    cout << count << endl;

    return 0;

}