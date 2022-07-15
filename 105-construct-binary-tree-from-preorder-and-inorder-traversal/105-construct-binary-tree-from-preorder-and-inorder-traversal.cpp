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
    TreeNode* solve(vector<int>& preorder,int preStart,int preEnd, vector<int>& inorder,int inStart,int inEnd,map<int,int>&inMap){
        if(preStart>preEnd || inStart>inEnd)return NULL;
        
        TreeNode* root = new TreeNode(preorder[preStart]);
        
        int inRoot = inMap[root->val];
        
        int nodesLeft = inRoot - inStart;
        
        root->left = solve(preorder,preStart+1,preStart+nodesLeft,inorder,inStart,inRoot-1,inMap);
        root->right = solve(preorder,preStart+nodesLeft+1,preEnd,inorder,inRoot+1,inEnd,inMap);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> inMap;
        for(int i=0;i<inorder.size();++i){
            inMap[inorder[i]] = i;
        }
        
        TreeNode* root = solve(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inMap);
        return root;
    }
};