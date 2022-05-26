class Solution {
public:
//     // using DFS
//     void dfs(int i,vector<vector<int>> &adjMat,vector<int>&vis){
//         int n = adjMat.size();
      
//         vis[i] = 1;
//         // check all its adj childs(for adj matrix)
//         for(int j=0;j<n;++j){
//             // adjMat[i][j]=1 && !vis[j] means there is edge between i and j and j is not vis
//             if(adjMat[i][j]==1 && !vis[j]){
//                 dfs(j,adjMat,vis);
//             }
//         }
//     }
    
//     int findCircleNum(vector<vector<int>>& adjMat) {
//         int n = adjMat.size();
        
//         vector<int> vis(n,0);
//         int connectedComponents = 0;
//         for(int i=0;i<n;++i){
//             if(!vis[i]){
//                 dfs(i,adjMat,vis);
//                 connectedComponents++;  
//             }  
//         }
//         return connectedComponents;
//     }
    
    
    
    
    
    
    
    // using DSU
    int rank[202];
    int par[202];
    int findPar(int a){
        if(a==par[a])return a;
        
        return par[a] = findPar(par[a]);
    }
    
    void _union(int a,int b,int &n){
        a = findPar(a);
        b = findPar(b);
        
        if(a!=b){
            if(rank[a]<rank[b]){
            par[a] = b;
            }
            else if(rank[a]>rank[b]){
                par[b] = a;
            }
            else{
                par[a] = b;
                rank[b]++;
            } 
            // initially assume all nodes are one component.
            // when 2 nodes merged -> number of components decrease by 1
            n--;
        } 
    }
    
    int findCircleNum(vector<vector<int>>& mat) {
        int n = mat.size();
        for(int i=0;i<202;++i){
            par[i] = i;
            rank[i] = 0;
        }
        
        for(int i=0;i<mat.size();++i){
            for(int j=0;j<mat[0].size();++j){
                if(mat[i][j]==1){
                    _union(i,j,n);
                }
            }
        }
        
        // return n;
        int cc = 0;
        for(int i=0;i<mat.size();++i){
            if(par[i] == i)cc++;
        }
        return cc;
    }
};