class Solution {
public:
    bool isSafe(char num,int row,int col,vector<vector<char>>&board){
        for(int i=0;i<9;++i){
            if(board[row][i]==num)return false;
            if(board[i][col]==num)return false;
            if(board[3*(row/3)+(i/3)][3*(col/3)+(i%3)]==num)return false;
        }
        return true;
    }
    
    bool solve(vector<vector<char>>&board){
        int n = board.size();
        
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                // if it is empty cell  -> try every possible number
                if(board[i][j] == '.'){
                    for(char num = '1';num<='9';++num){
                        if(isSafe(num,i,j,board)){
                            board[i][j] = num;
                            if(solve(board))return true;
                            board[i][j] = '.';  // try next number
                        }
                    }
                    return false; // if none of the number suits the current cell -> solution not possible for current setup of board
                }
            }
        }
        return true;    // tried every row and col -> and none of them returned false -> means we have one particular solution of the board
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};