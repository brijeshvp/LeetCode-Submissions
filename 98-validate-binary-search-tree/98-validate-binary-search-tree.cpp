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


// https://cplusplus.com/forum/general/85183/#:~:text=You%20can%20simply%20pass%20the%20pointer%20by%20reference,reference%20to%20a%20pointer%20to%20a%20node%20type%29.
// geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/
class Solution {
public:
    bool solve(TreeNode *root, TreeNode *&prev){
        if(root==NULL)return true;
        
        if(root){
            if(!solve(root->left,prev))return false;
            
            if(prev!=NULL && prev->val >= root->val)return false;
            
            prev = root;
            
            return solve(root->right,prev);
        }
        return true;
    }
    
    bool isValidBST(TreeNode* root) {
        TreeNode *prev = NULL;
        return solve(root,prev);
    }
};