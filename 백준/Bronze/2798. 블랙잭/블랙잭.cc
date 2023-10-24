#include <iostream>
using namespace std;

int cnt = 0;
int N, M;
int total= 0;

void Three(int order, int* arr, int sum);

int main()
{
    int arr[100];
    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    Three(0, arr, 0);

    cout << total << endl;

    return 0;
}

void Three(int order, int* arr, int sum)
{
    if(cnt == 3)
    {
        if(M >= sum)
        {
            total = total > sum ? total : sum;
        }
        
        return;
    }
    for(int i = order; i < N; i++)
    {
        sum += arr[i];
        cnt++;
        Three(i+1, arr, sum);
        cnt--;
        sum -= arr[i];
    }

    return;
}