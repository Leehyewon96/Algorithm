#include <iostream>
#include <set>
using namespace std;

    
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    set<int> s;
    int num;
    for (int i = 0; i < N; ++i)
    {
        cin >> num;
        s.insert(num);
    }

    for (set<int>::iterator it = s.begin(); it != s.end(); ++it)
    {
        cout << *it << '\n';
    }

    return 0;
}