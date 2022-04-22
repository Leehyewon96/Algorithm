#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int A, B, T;
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> A >> B;
        cout << A + B << "\n";
    }
    
    return 0;
}