#include <iostream>
#include <queue>
using namespace std;

int main(void) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        priority_queue<long long,vector<long long>, greater<long long>> pq;
        cin >> N;
        int num;
        for (int i = 0; i < N; ++i)
        {
            cin >> num;
            pq.push(num);
        }

        long long ans = 0;
        while (!pq.empty())
        {
            if (pq.size() == 1)
            {
                break;
            }
            long long first = pq.top();
            pq.pop();
            long long second = pq.top();
            pq.pop();
            ans += first + second;
            pq.push(first + second);
        }

        cout << ans << '\n';
    }

    return 0;
}