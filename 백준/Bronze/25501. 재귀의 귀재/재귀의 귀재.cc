#include <iostream>
#include <string.h>

using namespace std;

int recursion(int callNum, string str, int l, int r) {
    ++callNum;
    if (l >= r)
    {
        cout << 1 << " " << callNum << " ";
        return 1;
    }
    else if (str[l] != str[r])
    {
        cout << 0 << " " << callNum << " ";
        return 0;
    }
    else return recursion(callNum, str, l + 1, r - 1);
}


int isPalindrome(int CallNum, string str) {
    
    return recursion(CallNum, str, 0, str.length() - 1);
}

int main() 
{
    int T;
    int CallNum = 0;
    string str = "";
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        cin >> str;
        isPalindrome(CallNum, str);
        
        //초기화
        str = "";
        CallNum = 0;
    }
}