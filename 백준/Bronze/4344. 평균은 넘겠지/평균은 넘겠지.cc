#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int T, N;
    double avg, rate, scoreSum = 0, cnt = 0;
    cout << fixed;
    cout.precision(3);

    cin >> T;

    for(int i = 0; i < T; i++)
    {
        cin >> N;
        double score[N];
        for(int j = 0; j < N; j++)
        {
            cin >> score[j];
            scoreSum += score[j];
        }
        avg = (double)(scoreSum / N);
        for(int j = 0; j < N; j++)
        {
            if(score[j] > avg)
            {
                cnt += 1;
            }
        }
        rate = static_cast<double>(cnt) / static_cast<double>(N) * 100;
        cout << round(rate*1000)/1000 << "%" << endl;
        scoreSum = cnt = 0;
    }

    return 0;
}
