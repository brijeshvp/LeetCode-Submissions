class Solution {
public:
    /*
     1 
     1 1
     1 2 1 
     1 3 3 1
     1 4 6 4 1
    */
    vector<vector<int>> generate(int n) {
        if(n==1)return {{1}};
        if(n==2)return {{1},{1,1}};
        
        
        vector<vector<int>> res(n);
        for(int i=0;i<n;++i){
            res[i].resize(i+1,0);
        }
        
        res[1][1] = 1;
        
        for(int i=0;i<n;++i){
            res[i][0] = 1;
    
        }
        
        for(int i=2;i<n;++i){
            res[i][i] = 1;
        }
        
        for(int i=2;i<n;++i){
            for(int j=1;j<i;++j){
                res[i][j] = res[i-1][j-1] + res[i-1][j]; 
            }
        }
        
        
        return res;
    }
};