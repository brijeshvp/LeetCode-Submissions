class Solution {
public:
    void setZeroes(vector<vector<int>>& A) {
//     // space optimal approach-1 of dummy arrays row and col
//     // TC: O(m*n) and SC:O(1)
//     int m = A.size(), n = A[0].size(), _0thcol = 1;
//     for(int i=0;i<m;++i){
//         // check 0th col seperately
//         if(A[i][0]==0)_0thcol = 0;  // if any elt in 0th col = 0, then mark variable = 0 to indicate that all values in 0th col = 0
//         for(int j=1;j<n;++j){       // don't check 0th col values since it indicate row array(already checked in above if condition) 
//             if(A[i][j]==0)A[i][0] = A[0][j] = 0;
//         }
//     }

//     for(int i=m-1;i>=0;--i){
//         for(int j=n-1;j>=1;--j){   
//             if(A[i][0]==0 || A[0][j]==0)A[i][j] = 0;
//         }
//         // check 0th col seperately
//         if(_0thcol==0)A[i][0] = 0;  // do this after rest of the elts of that row is marks 0 
//     }
        
        
        
        
        
        // space optimal approach-2
        int m = A.size(), n = A[0].size(), _0thcol = 0, _0throw = 0;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                
                if(A[i][j] == 0){
                    if(i==0)_0throw = 1;
                    if(j==0)_0thcol = 1;
                    A[i][0] = 0; 
                    A[0][j] = 0;
                }
            }
        }
        
        for(int i=1;i<m;++i){
            for(int j=1;j<n;++j){
                if(A[i][0]==0 || A[0][j]==0)A[i][j] = 0;
            }
        }
        
        if(_0throw){
            for(int j=0;j<n;++j)A[0][j] = 0;
        }
        
        if(_0thcol){
            for(int i=0;i<m;++i)A[i][0] = 0;
        }
    }
};