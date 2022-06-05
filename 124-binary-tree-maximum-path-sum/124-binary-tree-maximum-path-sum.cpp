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
    long long mx = INT_MIN;
    long long solve(TreeNode* root){
        if(!root)return INT_MIN;
        
        long long left, right;
        left = solve(root->left);
        right = solve(root->right);
        
        mx = max(mx,1LL*root->val);
        mx = max(mx,max(left,right)+1LL*root->val);
        mx = max(mx,left+right+root->val);
        
        return max(0LL,max(left,right)) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return mx;
    }
};