#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int H, M, T; // H : 시작시각, M : 시작분, T : 걸리는시간(분단위)

    cin >> H >> M;
    cin >> T;

    int N = (M+T)/60; // N : M+T를 60으로 나눈 몫

    if(H+N < 24)
    {
        if(M+T < 60)
        {
            cout << H << " " << M+T << endl;
        }
        else if(M+T > 60)
        {
            cout << H+N << " " << (M+T)%60 << endl;
        }
        else if(M+T == 60)

        {
            cout << H+1 << " " << M+T-60 << endl;
        }
    }

    else if(H+N >= 24)
    {
        if(M+T < 60)
        {
            cout << H+N-24 << " " << M+T << endl;
        }
        else if(M+T > 60)
        {
            cout << H+N-24 << " " << (M+T)%60 << endl;
        }
        else if(M+T == 60)
        {
            cout << H+N-24 << " " << M+T-60 << endl;
        }
    }

    return 0;
}