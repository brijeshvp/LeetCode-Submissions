class Solution {
public:
//     vector<vector<int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};
//     bool solve(int i,int j, int x,vector<vector<char>> &b,string w,vector<vector<int>> &vis){
//         int m = b.size();
//         int n = b[0].size();
//         if(x==w.size())return true;
//         if(i<0 || j<0 || i>=m || j>=n)return false;
//         if(vis[i][j])return false;
//         if(b[i][j]!=w[x])return false;
        
//         vis[i][j] = 1;
        
//         bool flag = false;
//         for(auto &it : dir){
//             flag|= solve(i+it[0],j+it[1],x+1,b,w,vis);
//         }
//         vis[i][j] = 0;
//         return flag;
//     }
    
    
//     bool exist(vector<vector<char>>& b, string w) {
//         int m = b.size();
//         int n = b[0].size();
//         vector<vector<int>> vis(m,vector<int>(n,0));
//         bool flag = false;
//         for(int i=0;i<m;++i){
//             for(int j=0;j<n;++j){
//                 if(solve(i,j,0,b,w,vis)){
//                     return true;
//                 }       
//             }
//         }
//         return false;
//     }
    
    
    
    
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); ++i)
        {
            for(int j = 0; j < board[0].size(); ++j)
            {
                if(solve(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    
    }
protected:
    bool solve(vector<vector<char>>& board, const string& word, int i, int j, int index)
    {
        if(index == word.size()) return true; // end condition
        if(i < 0 || j < 0 || i > board.size()-1 || j > board[0].size()-1) return false; // boundary of matrix
        if(board[i][j] != word[index]) return false; // do not match
        // match!
        board[i][j] = '*'; // change the content, to avoid duplicated search
        bool res =  solve(board, word, i+1, j, index+1) || // up
                              solve(board, word, i-1, j, index+1) || // down
                              solve(board, word, i, j-1, index+1) || // left
                              solve(board, word, i, j+1, index+1);   // right
        
        board[i][j] = word[index]; // modify it back!
        return res;
    }
};

/*
    C A A
    A A A
    B C D
*/