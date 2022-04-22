#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int A, B, C;
    int count = 0;
    cin >> A;
    cin >> B;
    cin >> C;

    int result = A * B * C;
    int res = result;
    int n = 1;
    
    while(result / 10 != 0)
    {
        result /= 10;
        n++;
    }
    
    int arr[n];

    for(int i = 0; i < n; i++)
    {
        arr[i] = (res % (int)pow(10, n-i) / pow(10, n-i-1));
    }

    for(int i = 0; i <=9; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == arr[j])
            {
                count++;
            }
        }
        cout << count << endl;
        count = 0;
    }

    return 0;
}