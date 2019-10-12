/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */

// @lc code=start
class Solution
{
public:
    void solveSudoku(vector<vector<char>> &board)
    {
        dfs(board, 0, 0);
    }
    bool dfs(vector<vector<char>> &board, int i, int j)
    {
        if (i == 9)
            return true;
        if (j >= 9)
            return dfs(board, i + 1, 0);
        if (board[i][j] != '.')
            return dfs(board, i, j + 1);
        for (char c = '1'; c <= '9'; c++)
        {
            if (!isValid(board, i, j, c))
                continue;
            board[i][j] = c;
            if (dfs(board, i, j + 1))
                return true;
            board[i][j] = '.';
        }
        return false;
    }
    bool isValid(vector<vector<char>> &board, int row, int col, char val)
    {
        //处理行
        if (col > board[0].size() && col < 0)
            return false;
        if (row > board.size() && row < 0)
            return false;
        for (int i = 0; i < board[0].size(); i++)
        {
            //如果不符合规则，则回溯
            if (val == board[row][i])
                return false;
        }
        //处理列
        for (int i = 0; i < board.size(); i++)
        {
            if (val == board[i][col])
                return false;
        }
        //处理块
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (i == row && j == col)
                    continue;
                if (val == board[row / 3 * 3 + i][col / 3 * 3 + j])
                    return false;
            }
        }
        return true;
    }
};
// @lc code=end
