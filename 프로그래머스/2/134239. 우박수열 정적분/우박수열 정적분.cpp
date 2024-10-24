#include <string>
#include <vector>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    
    vector<pair<int, int>> arr;
    
    int x = 0;
    while(k != 1)
    {
        arr.push_back({x, k});
        
        if(k % 2 == 0)
        {
            k /= 2;
        }
        else
        {
            k = k * 3 + 1;
        }
        x++;
    }
    arr.push_back({x, k});
    
    vector<double> extent(x + 1);
    for(int i = 1; i <= x; i++)
    {
        extent[i] = (double)(arr[i - 1].second + arr[i].second) * 0.5; 
    }
    
    for(int i = 0; i < ranges.size(); i++)
    {
        int s = ranges[i][0];
        int e = x + ranges[i][1];
        
        if(s > e)
        {
            answer.push_back(-1);
            continue;
        }
        
        double ex = 0;
        for(int j = s + 1; j <= e; j++)
        {
            ex += extent[j];
        }
        
        answer.push_back(ex);
    }
    
    return answer;
}