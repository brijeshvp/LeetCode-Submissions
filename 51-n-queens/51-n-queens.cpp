class Solution {
public:
    bool isSafe(int row,int col,int n,vector<string>&board){
        int row_copy = row;
        int col_copy = col;
        
        while(row_copy>=0 && col_copy>=0){
            if(board[row_copy][col_copy]=='Q')return false;
            row_copy--;
            col_copy--;
        }
        
        row_copy = row;
        col_copy = col;
        while(col_copy>=0){
            if(board[row_copy][col_copy]=='Q')return false;
            col_copy--;
        }
        
        row_copy = row;
        col_copy = col;
        while(row_copy<n && col_copy>=0){
            if(board[row_copy][col_copy]=='Q')return false;
            row_copy++;
            col_copy--;
        }
        return true;
    }
    
    void solve(int col,int n,vector<vector<string>>&ans,vector<string>&board){
        // BC
        if(col==n){
            ans.push_back(board);
            return;
        }
        
        for(int row=0;row<n;++row){
            if(isSafe(row,col,n,board)){
                board[row][col] = 'Q';
                solve(col+1,n,ans,board);
                board[row][col] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        for(int i=0;i<n;++i){
            string s(n,'.');
            board[i] = s;
        }
        
        solve(0,n,ans,board);
        return ans;
    }
};