#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int cnt = 0, rCnt = 0;
    int arr[10];
    int arr1[10];

    for(int i = 0; i < 10; i++)
    {
        cin >> arr[i];
        arr1[i] = arr[i] % 42;
    }

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; i != j; j++)
        {
            if(arr1[i] == arr1[j])
            {
                cnt++;
            }
        }
        if(cnt == 0)
        {
            rCnt++;
        }
        cnt = 0;
    }

    cout << rCnt << endl;

    return 0;
    
}