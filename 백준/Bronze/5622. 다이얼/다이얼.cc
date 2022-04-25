#include <iostream>

using namespace std;

int main()
{
    int arr[26] = {3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10};
    int time = 0;
    string str;
    cin >> str;

    for(int i = 0; i < str.length(); i++)
    {
        int charNum = static_cast<int>(str[i])- static_cast<int>('A');
        time += arr[charNum];
    }

    cout << time << endl;
    return 0;
}