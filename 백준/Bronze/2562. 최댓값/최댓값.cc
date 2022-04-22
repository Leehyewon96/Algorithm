#include <iostream>
using namespace std;

int main()
{
    int arr[9];
    int num, count = 0, cnt = 0;

    for(int i = 0; i < 9; i++)
    {
        cin >> arr[i];
        //cout << endl;
    }

    num = arr[0]-1;

    for(int i = 0; i < 9; i++)
    {
        if(num < arr[i])
        {
            num = arr[i];
            count++;
            
            if(count != i + 1)
            {
                count = i + 1;
            }
        }
    }
    cout << num << endl;
    cout << count << endl;

    return 0;
}