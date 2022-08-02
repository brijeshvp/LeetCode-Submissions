class Solution {
public:
    // binary search solution
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        for(int i=0;i<n;++i){
            pq.push({matrix[i][0],{i,0}});
        }
        
        k--;
        while(k--){
            int val = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();
            
            if(j<n-1){
                pq.push({matrix[i][j+1],{i,j+1}});
            }
        }
        return pq.top().first;
    }
};