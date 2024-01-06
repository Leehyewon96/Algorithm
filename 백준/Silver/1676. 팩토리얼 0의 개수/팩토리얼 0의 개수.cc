#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    int cnt = 0;
    int temp = 5;
    while (n >= temp)
    {
        cnt += n / temp;
        temp *= 5;
    }
    cout << cnt;
    return 0;
}