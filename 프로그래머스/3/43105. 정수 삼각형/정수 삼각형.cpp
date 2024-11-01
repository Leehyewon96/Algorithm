#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<vector<int>> dp(triangle.size());
    
    dp[0].push_back(triangle[0][0]);
    for(int i = 1; i < triangle.size(); i++)
    {
        for(int j = 0; j < triangle[i].size(); j++)
        {
            int left = 0;
            int right = 0;
            if(j > 0)
            {
                left = dp[i - 1][j - 1];
            }
            
            if(j < triangle[i - 1].size())
            {
                right = dp[i - 1][j];
            }
            
            dp[i].push_back(triangle[i][j] + max(left, right));
        }
    }
    
    sort(dp.back().begin(), dp.back().end());
    answer = dp.back().back();
    
    return answer;
}