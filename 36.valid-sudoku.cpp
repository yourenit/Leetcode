/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */
//暴力解法
class Solution1 {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
       for(int i=0;i<9;i++){
           for(int j=0;j<9;j++){
               //行判断
               if(board[i][j] != '.'){
                   for(int k=0;k<j;k++){
                       if(board[i][k] == board[i][j] && k!=j)return false;
                   }
               }
               //列判断
               if(board[i][j] != '.'){
                   for(int k=0;k<i;k++){
                       if(board[i][j] == board[k][j] && k!=i)return false;
                   }
               }
               //块判断
               if(board[i][j] != '.'){
                   for(int k=i/3*3;k<i/3*3+3;k++){
                       for(int l=j/3*3;l<j/3*3+3;l++){
                           if(board[i][j] == board[k][l] && k!=i && l!=j)return false;
                       }
                   }
               }
           }
       }
       return true;
    }
};

//设置标志位
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int m=board.size(),n=board[0].size();
        vector<vector<bool>> rowFlag(m, vector<bool>(n, false));
        vector<vector<bool>> colFlag(m, vector<bool>(n, false));
        vector<vector<bool>> cellFlag(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] >= '1' && board[i][j] <= '9') {
                    int c = board[i][j] - '1';
                    if (rowFlag[i][c] || colFlag[c][j] || cellFlag[3 * (i / 3) + j / 3][c]) return false;
                    rowFlag[i][c] = true;
                    colFlag[c][j] = true;
                    cellFlag[3 * (i / 3) + j / 3][c] = true;
                }
            }
        }
        return true;
    }
};
