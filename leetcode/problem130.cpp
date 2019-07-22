

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (!board.size())
            return;
        vector<vector<int>> iboard(board.size(), vector<int>(board[0].size(), 0));
        stack<pair<int,int>> stk;
        for (int i = 0; i < board.size(); i++)
        {
            int l = 0, r = board[0].size() - 1;
            if (board[i][l] == 'O' && iboard[i][l] == 0)
            {
                stk.push(pair<int,int>(i,l));
                iboard[i][l] = 1;
            }
            if (board[i][r] == 'O' && iboard[i][r] == 0)
            {
                stk.push(pair<int,int>(i,r));
                iboard[i][r] = 1;
            }
        }
        for (int j = 0; j < board[0].size(); j++)
        {
            int u = 0, d = board.size()-1;
            if (board[u][j] == 'O' && iboard[u][j] == 0)
            {
                stk.push(pair<int,int>(u,j));
                iboard[u][j] = 1;
            }
            if (board[d][j] == 'O' && iboard[d][j] == 0)
            {
                stk.push(pair<int,int>(d,j));
                iboard[d][j] = 1;
            }
        }
        while (!stk.empty())
        {
            int option = 0;
            pair<int,int> point = stk.top();
            stk.pop();
            int row = point.first;
            int col = point.second;
            if (row >= 1 && iboard[row-1][col] == 0 && board[row-1][col] == 'O')
            {
                stk.push(pair<int,int>(row-1,col));
                iboard[row-1][col] = 1;
            }
            if (col < board[0].size()-1 && iboard[row][col+1] == 0 && board[row][col+1] == 'O')
            {
                stk.push(pair<int,int>(row,col+1));
                iboard[row][col+1] = 1;
            }
            if (row < board.size() - 1 && iboard[row+1][col] == 0 && board[row+1][col] == 'O')
            {
                stk.push(pair<int,int>(row+1,col));
                iboard[row+1][col] = 1;
            }
            if (col >= 1 && iboard[row][col-1] == 0 && board[row][col-1] == 'O')
            {
                stk.push(pair<int,int>(row,col-1));
                iboard[row][col-1] = 1;
            }
        }
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == 'O' && iboard[i][j] == 0)
                    board[i][j] = 'X';
            }
        }
    }
};