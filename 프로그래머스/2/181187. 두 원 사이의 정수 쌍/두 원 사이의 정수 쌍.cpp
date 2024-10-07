#include <string>
#include <vector>
#include <cmath>

using namespace std;
long long Calc(int x, int r, bool onCeil)
{
    if(x > r)
    {
        return 0;
    }
    
    double y = sqrt(pow(r, 2) - pow(x, 2));
    y = onCeil == true ? ceil(y) : floor(y);
    return y;
}

long long solution(int r1, int r2) {
    long long answer = 0;
    
    long long x = 1;
    long long overlaps = (r2 - r1 + 1) * 4;
    while(x < r2)
    {
        long long a = Calc(x, r1, true);
        long long b = Calc(x, r2, false);
        if(a == 0) a = 1;
        //if(b == 0) b = 1;
        answer += (b - a + 1);
        
        x++;
    }
    
    return (4 * answer) + overlaps;
}