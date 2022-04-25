#include <iostream>
using namespace std;

int main()
{
    int num1, num2, inv1, inv2;
    cin >> num1 >> num2;

    inv1 = ((num1 % 10) * 100) + ((num1 % 100) / 10) * 10 + (num1 / 100);
    inv2 = ((num2 % 10) * 100) + ((num2 % 100) / 10) * 10 + (num2 / 100);

    if(inv1 > inv2)
    {
        cout << inv1 << "\n";
    }
    else
    {
        cout << inv2 << "\n";
    }

    return 0;
}