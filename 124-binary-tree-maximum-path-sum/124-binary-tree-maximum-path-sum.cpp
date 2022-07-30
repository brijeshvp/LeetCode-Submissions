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
    // extension of diameter of a tree
    int mx = INT_MIN;
    int solve(TreeNode* root){
        if(!root)return INT_MIN;
        
        int left, right;
        left = max(0,solve(root->left));
        right = max(0,solve(root->right));
        
        mx = max(mx,left+right+root->val);
        
        return max(left,right) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return mx;
    }
};