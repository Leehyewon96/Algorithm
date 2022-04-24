#include <iostream>
#include <string>

using namespace std;
void add(int n);

int main()
{
    int n;

    cin >> n;
    add(n);

    return 0;
}

void add(int n)
{
    int sum = 0;
    string num;
    cin >> num;

    for(int i = 0; i < n; i++)
    {
        sum += (num[i]-48);
    }

    cout << sum << "\n";
}