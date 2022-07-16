class Solution {
public:
//     // backtracking solution    -> wrong ans
//     int maxcherries = 0;
//     void solve2(int i,int j,vector<vector<int>> &grid,int cherrycollected){
//         int n = grid.size();
//         if(i<0 || j<0 || i>=n || j>=n)return;
//         if(grid[i][j] == -1)return;
//         if(i==0 && j==0){
//             maxcherries = max(maxcherries,cherrycollected+grid[i][j]);
//             return;      
//         }
        
//         int cherry = grid[i][j];
//         grid[i][j] = 0;
//         solve2(i-1,j,grid,cherrycollected+cherry);
//         solve2(i,j-1,grid,cherrycollected+cherry);
//     }
    
//     void solve(int i,int j,vector<vector<int>> &grid,int cherrycollected){
//         int n = grid.size();
//         if(i<0 || j<0 || i>=n || j>=n)return;
//         if(grid[i][j] == -1)return;
        
//         if(i==n-1 && j==n-1){
//             solve2(i,j,grid,cherrycollected);
//             return;
//         }
        
//         int cherry = grid[i][j];
//         grid[i][j] = 0;
//         solve(i+1,j,grid,cherrycollected+cherry);
//         solve(i,j+1,grid,cherrycollected+cherry);
//         grid[i][j] = cherry;
//     }
    
//     int cherryPickup(vector<vector<int>>& grid) {
//         int n = grid.size();
//         solve(0,0,grid,0);
//         return maxcherries;
//     }
    
    
    // 1 bande ka last tak jana and vapis upar tak ana is equivalent to 2 bando ka last tak jana
//     // 4d dp
//     long long solve(int r1,int c1,int r2,int c2,vector<vector<int>> &grid,vector<vector<vector<vector<int>>>> &dp){
//         int n = grid.size();
//         if(r1>=n || c1>=n || r2>=n || c2>=n)return INT_MIN;
//         if(grid[r1][c1]==-1 || grid[r2][c2]==-1)return INT_MIN;
//         // cout<<"r1:"<<r1<<" c1:"<<c1<<" r2:"<<r2<<" c2:"<<c2<<endl;
//         // both robots reach last cell simultanously -> THINK! (thus need to check for any dimension whether reached end or not)
//         if(r1==n-1 && c1==n-1)return grid[r1][c1];
//         if(dp[r1][c1][r2][c2]!=-1)return dp[r1][c1][r2][c2];
        
//         int cherries = 0;
//         if(r1==r2 && c1==c2)cherries+= grid[r1][c1];
//         else cherries+= (grid[r1][c1] + grid[r2][c2]);
        
//         // d : down and r : right
//         int ans1 = solve(r1+1,c1,r2+1,c2,grid,dp); // dd
//         int ans2 = solve(r1+1,c1,r2,c2+1,grid,dp);   // dr
//         int ans3 = solve(r1,c1+1,r2+1,c2,grid,dp);   // rd
//         int ans4 = solve(r1,c1+1,r2,c2+1,grid,dp);   // rr
        
//         int temp = max({ans1,ans2,ans3,ans4});
//         if(temp==INT_MIN)return dp[r1][c1][r2][c2] = INT_MIN;
//         return dp[r1][c1][r2][c2] = cherries + temp;
//     }
    
//     int cherryPickup(vector<vector<int>>& grid) {
//         int n = grid.size();
//         vector<vector<vector<vector<int>>>> dp(n,vector<vector<vector<int>>>(n,vector<vector<int>>(n,vector<int>(n,-1))));
//         int ans = solve(0,0,0,0,grid,dp);
//         // NOTE: for invalid states we will return INT_MIN so that no cherries is counted until we reach last cell
//         // thus check -> if ans = INT_MIN, return 0
//         if(ans==INT_MIN)return 0;
//         return ans;
//     }
    
    
    
    // space optimization(4D DP -> 3D DP)
    // NOTE: both robots takes 1 step simultanously either in right or down
    // -> thus at any state -> r1 + c1 = r2 + c2
    // thus if i know any 3 variables, 4th will be gettable
    // reduce 4D DP -> 3D DP
    // lets say we maintain r1,c1,r2 and obtain c2 = r1 + c1 - r2
    // thus dp ka state = r1,c1,r2
    long long solve(int r1,int c1,int r2,vector<vector<int>> &grid,vector<vector<vector<int>>> &dp){
        // 1st step -> before doing anything is to obtain 4th parameter(c2)
        int c2 = r1 + c1 - r2;
        int n = grid.size();
        if(r1>=n || c1>=n || r2>=n || c2>=n)return INT_MIN;
        if(grid[r1][c1]==-1 || grid[r2][c2]==-1)return INT_MIN;
        // cout<<"r1:"<<r1<<" c1:"<<c1<<" r2:"<<r2<<" c2:"<<c2<<endl;
        // both robots reach last cell simultanously -> THINK! (thus need to check for any dimension whether reached end or not)
        if(r1==n-1 && c1==n-1)return grid[r1][c1];
        if(dp[r1][c1][r2]!=-1)return dp[r1][c1][r2];
        
        int cherries = 0;
        if(r1==r2 && c1==c2)cherries+= grid[r1][c1];
        else cherries+= (grid[r1][c1] + grid[r2][c2]);
        
        // d : down and r : right
        int ans1 = solve(r1+1,c1,r2+1,grid,dp); // dd
        int ans2 = solve(r1+1,c1,r2,grid,dp);   // dr
        int ans3 = solve(r1,c1+1,r2+1,grid,dp);   // rd
        int ans4 = solve(r1,c1+1,r2,grid,dp);   // rr
    
        int temp = max({ans1,ans2,ans3,ans4});
        if(temp==INT_MIN)return dp[r1][c1][r2] = INT_MIN;
        return dp[r1][c1][r2] = cherries + temp;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(n,-1)));
        int ans = solve(0,0,0,grid,dp);
        // NOTE: for invalid states we will return INT_MIN so that no cherries is counted until we reach last cell
        // thus check -> if ans = INT_MIN, return 0
        if(ans==INT_MIN)return 0;
        return ans;
    }
};