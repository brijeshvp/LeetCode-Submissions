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
    // node = i -> left child = 2i+1 and right child = 2i+2
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        
        long long ans = 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            int sz = q.size();
            int minIndex = q.front().second;
            long long first,last;
            for(int i=0;i<sz;++i){
                TreeNode* node = q.front().first;
                long long index = q.front().second - minIndex;
                q.pop();
                
                if(i==0)first = index;
                if(i==sz-1)last = index;
                
                if(node->left)q.push({node->left,2*index+1});
                if(node->right)q.push({node->right,2*index+2});
            }
            ans = max(ans,last-first+1);
        }
        return ans;
    }
};