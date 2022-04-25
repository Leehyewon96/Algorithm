#include <iostream>
using namespace std;

int main()
{
    int N, sum = 1;
    cin >> N;

    int i = 1;
    while(N > sum)
    {
        sum += 6*i;
        i++;
    }

    if(N == 1)
    {
        int i = 1;
        cout << i;
    }
    else
    {
        cout << i;
    }

    return 0;
}