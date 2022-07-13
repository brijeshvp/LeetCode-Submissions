class Solution {
public:
    // m*n 
    // m*logn
    bool searchMatrix(vector<vector<int>>& mat, int t) {
        int m = mat.size(), n = mat[0].size();
        
        int i = 0, j = n-1;
        while(i<m && j>=0){
            if(mat[i][j]==t)return true;
            
            if(mat[i][j]<t) i++;
            else if(mat[i][j]>t)j--;   
        }
        return false;
    }
};