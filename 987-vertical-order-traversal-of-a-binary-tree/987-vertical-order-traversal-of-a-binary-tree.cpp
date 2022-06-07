/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        if(!root)return res;
        
        map<int,map<int,multiset<int>>> mp;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            
            TreeNode* node = it.first;
            int horDist = it.second.first;
            int vertDist = it.second.second;
            
            mp[horDist][vertDist].insert(node->val);
            
            if(node->left)q.push({node->left,{horDist-1,vertDist+1}});
            if(node->right)q.push({node->right,{horDist+1,vertDist+1}});
        }
        
        for(auto &it : mp){
            vector<int> col;
            for(auto &i : it.second){
                for(int val : i.second)col.push_back(val);
            }
            res.push_back(col);
        }
        
        return res;
    }
};