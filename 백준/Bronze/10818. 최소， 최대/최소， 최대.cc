#include <iostream>
using namespace std;

int main()
{
    int N, cMax, cMin;
    cin >> N;

    int arr[N];
    
    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    cMax = arr[0];
    cMin = arr[0];

    for(int i = 0; i < N; i++)
    {
        if(cMax <= arr[i] )
        {
            cMax = arr[i];
        }
        if(cMin >= arr[i])
        {
            cMin = arr[i];
        }
    }
    printf("%d %d\n", cMin, cMax);

}