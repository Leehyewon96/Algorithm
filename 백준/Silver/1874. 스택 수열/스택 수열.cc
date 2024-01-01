#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;


int main()
{
    int n, temp, cnt = 0;
    int m = 1; // 스택에 대입할 수
    int j = 0;
    string ans;
    stack<int> s;
    cin >> n;
    int arr[n + 1];
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        arr[i] = temp;
    }

    do
    {
        while(m <= arr[j])
        {
            s.push(m);
            ans += '+';
            m++;
        }
        if(s.top() == arr[j])
        {
            s.pop();
            ans += '-';
            j++;
        }
        else
        {
            cout << "NO" << "\n";
            return 0;
        }

    }while(j < n);

    for(int i = 0; i < ans.length(); i++)
    {
        cout << ans[i] << "\n";
    }

    return 0;
}