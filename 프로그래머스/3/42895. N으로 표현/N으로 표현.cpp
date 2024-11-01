#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int Convert(int N, int cnt)
{
    int digit = 1;
    int num = 0;
    while(cnt--)
    {
        num += digit * N;
        digit *= 10;
    }
    
    return num;
}

int solution(int N, int number) {
    int answer = -1;
    
    if(N == number)
    {
        return 1;
    }
    
    vector<set<int>> dp(9);
    
    for(int i = 1; i < 9; i++)
    {
        dp[i].insert(Convert(N, i));
        
        for(int j = 1; j < i; j++)
        {
            for(int k = 1; k < i; k++)
            {
                if(j + k != i)
                {
                    continue;
                }
                
                for(int a : dp[j])
                {
                    for(int b : dp[k])
                    {
                        dp[i].insert(a + b);
                        
                        if(a - b > 0)
                        {
                            dp[i].insert(a - b);
                        }
                        
                        dp[i].insert(a * b);
                        
                        if(b != 0 && a % b == 0)
                        {
                            dp[i].insert(a / b);
                        }
                    }
                }
            }
        }
    }
    
    for(int i = 0; i < dp.size(); i++)
    {
        auto it = find(dp[i].begin(), dp[i].end(), number);
        if(it != dp[i].end())
        {
            answer = i;
            break;
        }
    }
    
    return answer;
}