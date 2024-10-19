#include <string>
#include <vector>

using namespace std;

bool Check(const vector<string>& board, char ch)
{
    for(int i = 0; i < board.size(); i++)
    {
        if(ch == board[i][0] && board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            return true;
        }
        
        if(ch == board[0][i] && board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            return true;
        }
    }
    
    
    //대각선
    if(board[0][0] == ch && board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        return true;
    }
    
    if(board[0][2] == ch && board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        return true;
    }
    
    return false;
}

int solution(vector<string> board) {
    
    int no = 0;
    int nx = 0;
    
    
    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board[i].size(); j++)
        {
            if(board[i][j] == 'O')
            {
                no++;
            }
            else if(board[i][j] == 'X')
            {
                nx++;
            }
        }
    }
    
    if(no < nx)
    {
        return 0;
    }
    
    if(no - nx > 1)
    {
        return 0;
    }
    
    if(Check(board, 'O') && no - nx != 1)
    {
        return 0;
    }
    else if(Check(board, 'X') && no - nx != 0)
    {
        return 0;
    }
    else if(Check(board, 'O') && Check(board, 'X'))
    {
        return 0;
    }
    
    return 1;
}