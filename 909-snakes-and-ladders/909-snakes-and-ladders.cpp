class Solution {
public:
    pair<int,int> squareToCell(int cellNo,int boardSize){
        int row = (cellNo-1)/boardSize;
        int col = (cellNo-1)%boardSize;
        if(row%2 == 1){
            col = (boardSize-1) - col;
        }
        return {row,col};
    }
    
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        reverse(board.begin(),board.end());
        
        queue<pair<int,int>> q;
        set<int> vis;
        q.push({1,0});
        vis.insert(1);
        
        while(!q.empty()){
            int currNode = q.front().first;
            int dist = q.front().second;
            q.pop();
            
            for(int i=1;i<=6;++i){
                int nextNode = currNode + i;
                auto it = squareToCell(nextNode,n);
                int row = it.first, col = it.second;
                
                if(board[row][col]!=-1)nextNode = board[row][col];
                
                if(nextNode == n*n)return dist+1;
                
                if(!vis.count(nextNode)){
                    vis.insert(nextNode);
                    q.push({nextNode,dist+1});
                }
            }
        }
        return -1;
    }
};