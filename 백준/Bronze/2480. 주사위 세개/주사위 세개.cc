#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int dice1, dice2, dice3;

    cin >> dice1 >> dice2 >> dice3;

    if(dice1 == dice2 && dice2 == dice3)
    {
        cout << 10000 + (dice1 * 1000) << endl;
    }
    else if(dice1 == dice2 || dice2 == dice3 || dice1 == dice3)
    {
        if(dice1 == dice2 || dice2 == dice3)
        {
            cout << 1000 + (dice2 * 100) << endl;
        }
        else if(dice1 == dice3)
        {
            cout << 1000 + (dice1 * 100) << endl;
        }
    }
    else
    {
        if (max(dice2, dice3) < dice1)
        {
            cout << 100 * dice1 << endl;
        }
        else 
        {
            cout << 100 * max(dice2, dice3) << endl;
        }
    }

    return 0;
}