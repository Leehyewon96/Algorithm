#include <iostream>

using namespace std;

int main()
{
    int A, B, C; // A : 고정비용, B : 가변비용, C : 노트북 가격
    cin >> A >> B >> C;
    
    if(B >= C)
    {
        cout << "-1" << endl;
    }
    else
    {
        cout << A / (C - B) + 1;
    }

    return 0;
}