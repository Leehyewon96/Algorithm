#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    int level = *max_element(diffs.begin(), diffs.end());
    long long curtime = 0;
    
    int left = 1;
    int right = level;
    
    while(left <= right)
    {
        int mid = (left + right) / 2;
        
        curtime = 0;
        for(int i = 0; i < diffs.size(); ++i)
        {
            if(i > 0 && mid < diffs[i])
            {
                curtime += (times[i] + times[i - 1]) * (diffs[i] - mid);
            }
        
            curtime += times[i];
        }
        
        if(curtime > limit)
        {
            left = mid + 1;
        }
        else
        {
            level = mid;
            right = mid - 1;
        }
    }
    
    
    
    answer = level;
    return answer;
}