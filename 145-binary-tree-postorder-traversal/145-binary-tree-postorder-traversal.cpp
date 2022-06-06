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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> post;
        
		if(!root)return post;
        
		TreeNode* pre = NULL;
        stack<TreeNode*> st;
		while(!st.empty() || root!=NULL){
			if(root!=NULL){				
				st.push(root);
				root = root->left;
			}
			else{
				root = st.top();
				if(root->right==NULL || root->right==pre){
				    post.push_back(root->val);
				    st.pop();
				    pre=root;
				    root = NULL;
				}
				else root = root->right;
			}
		}
		return post;
    }
};