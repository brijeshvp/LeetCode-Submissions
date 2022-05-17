/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* solve(TreeNode* root,int val){
        if(root==NULL)return NULL;
        
        if(root->val==val)return root;
        
        TreeNode* ans1 = solve(root->left,val);
        TreeNode* ans2 = solve(root->right,val);
        
        if(ans1==NULL && ans2==NULL)return NULL;
        
        if(ans1!=NULL)return ans1;
        
        return ans2;
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        int val = target->val;
        
        return solve(cloned,val);
    }
};