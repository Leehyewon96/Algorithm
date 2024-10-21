#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int storey) {
    int answer = 0;
    
    while(storey != 0)
    {
        int temp = abs(storey);
        int digit = 1;
        while(temp / digit != 0)
        {
            digit *= 10;
        }
        
        answer++;
        if(abs(temp - digit) > abs(temp - (digit / 10)))
        {
            storey = temp - (digit / 10);
        }
        else
        {
            storey = temp - digit;
        }
           
    }
    
    
    
    
    return answer;
}