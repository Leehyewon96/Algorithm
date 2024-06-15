#include <iostream>
#include <tuple>
#include <vector>
#include <queue>

using namespace std;

bool visited[2001][2001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B, C;

    cin >> A >> B >> C;

    queue<tuple<int, int, int>> q;
    q.push(make_tuple(A, B, C));

    visited[A][B] = 1;
    visited[B][A] = 1;
    visited[A][C] = 1;
    visited[C][A] = 1;
    visited[B][C] = 1;
    visited[C][B] = 1;

    while (!q.empty())
    {
        tuple<int, int, int> front = q.front();
        int a = get<0>(front);
        int b = get<1>(front);
        int c = get<2>(front);

        q.pop();

        if (a == b && b == c)
        {
            cout << 1;
            return 0;
        }

        if (a - b > 0 && !visited[a - b][b + b])
        {
            visited[a - b][b + b] = true;
            q.push(make_tuple(a - b, b + b, c));
        }
        if (b - a > 0 && !visited[a + a][b - a])
        {
            visited[a + a][b - a] = true;
            q.push(make_tuple(a + a, b - a, c));
        }
        if (b - c > 0 && !visited[b - c][c + c])
        {
            visited[b - c][c + c] = true;
            q.push(make_tuple(a, b - c, c + c));
        }
        if (c - b > 0 && !visited[b + b][c - b])
        {
            visited[b + b][c - b] = true;
            q.push(make_tuple(a, b + b, c - b));
        }
        if (a - c > 0 && !visited[a - c][c + c])
        {
            visited[a - c][c + c] = true;
            q.push(make_tuple(a - c, b, c + c));
        }
        if (c - a > 0 && !visited[a + a][c - a])
        {
            visited[a + a][c - a] = true;
            q.push(make_tuple(a + a, b, c - a));
        }
    }
    
    cout << 0;
    return 0;
}