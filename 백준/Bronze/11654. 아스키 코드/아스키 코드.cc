#include <iostream>

using namespace std;

void aski(char input);

int main()
{
    char input;
    cin >> input;
    aski(input);

    return 0;
}

void aski(char input)
{
    cout << static_cast<int>(input) << "\n";
}