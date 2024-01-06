#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int numOfzero(int n, int divideNum);

int main()
{
    long n, m;
    cin >> n >> m;
    
    int numof2 = numOfzero(n, 2) - numOfzero(n - m, 2) - numOfzero(m, 2);
    int numof5 = numOfzero(n, 5) - numOfzero(n - m, 5) - numOfzero(m, 5);
    cout << min(numof2, numof5);
    return 0;
}

int numOfzero(int n, int divideNum)
{
    long cnt = 0;
    long temp = divideNum;
    while (n >= temp)
    {
        cnt += n / temp;
        temp *= divideNum;
    }
    return cnt;
}