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
    bool solve(TreeNode *root, long long lo, long long hi){
        if(root==NULL)return true;
        
        if(root->val < lo || root->val > hi)return false;
        
        bool left = solve(root->left,lo,1LL*root->val-1);
        bool right = solve(root->right,1LL*root->val+1,hi);
        
        return left && right;
    }
    
    bool isValidBST(TreeNode* root) {
        return solve(root,INT_MIN,INT_MAX);
    }
};