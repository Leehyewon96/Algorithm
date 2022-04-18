#include <iostream>

using namespace std;

int main()
{
    int H, M;

    cin >> H >> M;
    
    if(H>0)
    {    
        if(M > 45)
        {
            cout << H << " " << M-45 << endl;
        }
        else if(45>M)
        {
            cout << H-1 << " " << M+15 << endl;
        }
        else if(M == 45)
        {
            cout << H << " " << M-45 << endl;
        }
    }

    if(H == 0)
    {
        if(M > 45)
        {
            cout << H << " " << M-45 << endl;
        }
        else if(45>M)
        {
            cout << H+23 << " " << M+15 << endl;
        }
        else if(M == 45)
        {
            cout << H << " " << M-45 << endl;
        }
    }
    return 0;
}