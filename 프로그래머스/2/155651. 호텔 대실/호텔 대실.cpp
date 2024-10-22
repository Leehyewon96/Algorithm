#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int GetTime(string time)
{
    string h = time.substr(0,2);
    string m = time.substr(3, 2);
    
    int ih = stoi(h);
    int im = stoi(m);
    
    return ih * 60 + im;
}

int solution(vector<vector<string>> book_time) {
    
    int answer = 1;
    
    vector<pair<int, int>> bookVec;
    for(int i = 0; i < book_time.size(); i++)
    {
        bookVec.push_back({GetTime(book_time[i][0]), GetTime(book_time[i][1])});
    }
    
    sort(bookVec.begin(), bookVec.end());
    
    priority_queue<int> pq;
    pq.push(-bookVec[0].second - 10);
    for(int i = 1; i < bookVec.size(); i++)
    {
        if(bookVec[i].first >= -pq.top())
        {
            answer--;
            pq.pop();
        }
        
        answer++;
        pq.push(-bookVec[i].second - 10);
    }

    return answer;
}