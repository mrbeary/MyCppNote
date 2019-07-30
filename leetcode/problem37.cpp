
//利用递归
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        rows = vector<vector<int>>(9,vector<int>(9,0));  //记录每行已被使用的数字
        //0表示未用，1表示已用
        cols = vector<vector<int>>(9,vector<int>(9,0));  //记录每列已被使用的数字
        boxes = vector<vector<int>>(9,vector<int>(9,0)); //记录每个九宫格已被使用的数字
        cboard = board;
        over = false; //结束标志，用于判断递归什么时候返回
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {//读取输入的棋盘信息
                if (board[i][j] == '.')  //对应于未填的格子
                {
                    eptcell.push(pair<int,int>(i,j)); //将待填的格子坐标放入栈里面
                    continue;
                }
                int tmp = board[i][j] - '0' - 1; //将char 转换为整数，因为我们用来记录的数组是从0开始计数，所以这里要减1
                rows[i][tmp] = 1; //对应行的对应数字置 1，表示已用
                cols[j][tmp] = 1; //对应列的对应数字置 1，表示已用
                int tbox = i / 3 * 3 + j / 3; //计算对应的九宫格编号
                boxes[tbox][tmp] = 1; //对应九宫格的对应数字置1，表示已用
            }
        }
        fillTheCell(); //开填格子
        board = cboard;
    }

private:
    vector<vector<int>> rows, cols, boxes;
    stack<pair<int,int>> eptcell;
    vector<vector<char>> cboard;
    bool over;

    bool isvalid(int r, int c, int v)
    {  //这个函数用来判断在行r，列c是否可以填入数字v，我们假设v是0~8的数字（对应1~9分别减1）
        //如果可以填就返回true，否则返回false
        int b = r / 3 * 3 + c / 3;
        return !rows[r][v] && !cols[c][v] && !boxes[b][v];
    }

    void fillTheCell()
    {
        vector<int> used(9,0); //记录目前格子已经用过的数字，置1表示已用
        if (eptcell.empty())
        {
            over = true; //结束标志为true时直接返回
            return;
        }
        if (!eptcell.empty())
        {
            pair<int,int> curPos = eptcell.top();
            eptcell.pop();
            while (!over)
            {
                for (int i = 0; i < 9; i++)
                {
                    int r = curPos.first, c = curPos.second, b = curPos.first / 3 * 3 + curPos.second/3;
                    if (isvalid(r, c, i) && !used[i]) //判断是否可填
                    {
                        rows[r][i] = 1;
                        cols[c][i] = 1;
                        boxes[b][i] = 1; //对应记录数组置1，表示数字已被使用
                        cboard[r][c] = i + 1 + '0'; 
                        fillTheCell(); //填下一个
                        if (over)
                            return; //如果填完了直接返回
                        rows[r][i] = 0;
                        cols[c][i] = 0;
                        boxes[b][i] = 0; //对应记录数组对应位置置0，表示数字可用，开始找下一个数字
                    }
                }
                eptcell.push(curPos); //试完当前所有可能性都不ok，就将这个点推入栈，返回上一层递归来尝试填其它数
                return;
            }
        }
    }
};
