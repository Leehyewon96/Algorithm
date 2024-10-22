#include <cmath>
#include <vector>
#include <climits>

using namespace std;

int calc_dist(int m, int n, int a, int b, int c, int d)
{
    int total=INT_MAX;
    if(a!=c || b<=d) total=min(total, (int)(pow(a-c, 2)+pow(b+d, 2)));
    if(a>=c || b!=d) total=min(total, (int)(pow(a-2*m+c, 2)+pow(b-d, 2)));
    if(a!=c || b>=d) total=min(total, (int)(pow(a-c, 2)+pow(b-2*n+d, 2)));
    if(a<=c || b!=d) total=min(total, (int)(pow(a+c, 2)+pow(b-d, 2)));
    return total;
}

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls)
{
    vector<int> answer;

    for(int i=0; i<balls.size(); i++)
        answer.push_back(calc_dist(m, n, startX, startY, balls[i][0], balls[i][1]));

    return answer;
}