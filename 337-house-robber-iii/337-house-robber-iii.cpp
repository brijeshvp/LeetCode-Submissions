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
    int dfs(TreeNode* root,map<TreeNode*,int> &dp){
        if(root==NULL)return 0;
        if(dp.count(root))return dp[root];
        
        // choice 1 -> pick curr root
        int sum1 = root->val;
        if(root->left!=NULL){
            sum1+=dfs(root->left->left,dp);
            sum1+=dfs(root->left->right,dp);
        }
        if(root->right!=NULL){
            sum1+=dfs(root->right->left,dp);
            sum1+=dfs(root->right->right,dp);
        }
        //choice 2 -> don't pick curr root
        int sum2= dfs(root->left,dp) + dfs(root->right,dp);
        
        return dp[root] = max(sum1,sum2);
    }
    
    int rob(TreeNode* root) {
        map<TreeNode*,int> dp;
        return dfs(root,dp);
    }
};