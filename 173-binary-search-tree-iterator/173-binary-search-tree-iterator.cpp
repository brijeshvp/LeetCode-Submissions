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
class BSTIterator {
public:
//     // bruteforce
//     vector<int> inorder;
//     int i;
//     void solve(TreeNode* root){
//         if(root==NULL)return;
        
//         solve(root->left);
//         inorder.push_back(root->val);
//         solve(root->right);
//     }
    
//     BSTIterator(TreeNode* root) {
//         // this->root = root;
//         i = -1;
//         inorder.resize(0,0);
//         solve(root);
//     }
    
//     int next() {
//         i++;
//         return inorder[i];
//     }
    
//     bool hasNext() {
//         return (i+1>=inorder.size())?0:1;
//     }
    
    
    stack<TreeNode*> st;
    void pushLefts(TreeNode* root){
        if(!root)return;
        
        TreeNode* cur = root;
        while(cur!=NULL){
            st.push(cur);
            cur = cur->left;
        }
    }
    
    BSTIterator(TreeNode* root) {
        pushLefts(root);
    }
    
    int next() {
        TreeNode* cur = st.top();
        st.pop();
        pushLefts(cur->right);
        return cur->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */