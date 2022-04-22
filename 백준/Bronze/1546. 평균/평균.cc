#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int N, max;
    double newSum = 0, avg;
    cin >> N;

    double arr[N], newArr[N];
    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    max = arr[0]-1;
    for(int i = 0; i < N; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }

    for(int i = 0; i < N; i++)
    {
        if(arr[i] <= max)
        {
            newArr[i] = (double)(arr[i]/max*100);
        }
        newSum += newArr[i]; 
    }

    avg = newSum / N;

    cout << avg << endl;

    return 0;
}