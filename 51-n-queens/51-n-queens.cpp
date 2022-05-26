class Solution {
public:
//     // brute force 
//     bool isSafe(int row,int col,int n,vector<string>&board){
//         int row_copy = row;
//         int col_copy = col;
        
//         while(row_copy>=0 && col_copy>=0){
//             if(board[row_copy][col_copy]=='Q')return false;
//             row_copy--;
//             col_copy--;
//         }
        
//         row_copy = row;
//         col_copy = col;
//         while(col_copy>=0){
//             if(board[row_copy][col_copy]=='Q')return false;
//             col_copy--;
//         }
        
//         row_copy = row;
//         col_copy = col;
//         while(row_copy<n && col_copy>=0){
//             if(board[row_copy][col_copy]=='Q')return false;
//             row_copy++;
//             col_copy--;
//         }
//         return true;
//     }
    
//     void solve(int col,int n,vector<vector<string>>&ans,vector<string>&board){
//         // BC
//         if(col==n){
//             ans.push_back(board);
//             return;
//         }
        
//         for(int row=0;row<n;++row){
//             // isSafe function will take -> O(3n) to check whether can place queen in that row
//             if(isSafe(row,col,n,board)){
//                 board[row][col] = 'Q';
//                 solve(col+1,n,ans,board);
//                 board[row][col] = '.';
//             }
//         }
//     }
    
//     vector<vector<string>> solveNQueens(int n) {
//         vector<vector<string>> ans;
//         vector<string> board(n);
//         for(int i=0;i<n;++i){
//             string s(n,'.');
//             board[i] = s;
//         }
        
//         solve(0,n,ans,board);
//         return ans;
//     }
    
    
    
    
    
    
    
    
    
    // optimized using extra space(hashing) 
    bool isSafe(int row,int col,int n,vector<int>&upperDiagonal,vector<int>&leftRow,vector<int>&lowerDiagonal){
        if(upperDiagonal[(n-1) + (col-row)]==0 && leftRow[row]==0 && lowerDiagonal[row+col]==0)return true;
        return false;
    }
    
    void solve(int col,int n,vector<vector<string>>&ans,vector<string>&board,vector<int>&upperDiagonal,vector<int>&leftRow,vector<int>&lowerDiagonal){
        // BC
        if(col==n){
            ans.push_back(board);
            return;
        }
        
        for(int row=0;row<n;++row){
            // isSafe function will take -> O(1) to check whether can place queen in that row since hashing using extra space
            if(isSafe(row,col,n,upperDiagonal,leftRow,lowerDiagonal)){
                board[row][col] = 'Q';
                upperDiagonal[(n-1) + (col-row)] = 1;
                leftRow[row] = 1;
                lowerDiagonal[row+col] = 1;
                solve(col+1,n,ans,board,upperDiagonal,leftRow,lowerDiagonal);
                board[row][col] = '.';
                upperDiagonal[(n-1) + (col-row)] = 0;
                leftRow[row] = 0;
                lowerDiagonal[row+col] = 0;
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
        
        vector<int> upperDiagonal(2*n-1,0), leftRow(n,0), lowerDiagonal(2*n-1,0);
        solve(0,n,ans,board,upperDiagonal,leftRow,lowerDiagonal);
        return ans;
    }
};