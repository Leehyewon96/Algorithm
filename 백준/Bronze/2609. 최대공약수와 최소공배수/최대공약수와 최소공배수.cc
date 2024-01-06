#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int GCD(int m, int n);

int main()
{
    int m, n;
    cin >> m >> n;

    cout << GCD(m, n) << ' ';
    
    //LCM
    int lcm = (m * n) / GCD(m, n);
    cout << lcm;
    return 0;
}

int GCD(int m, int n)
{
    //GCD
    while (n != 0)
    {
        int temp = m % n;
        m = n;
        n = temp;
    }
    return m;
}