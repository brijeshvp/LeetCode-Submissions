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
//     void build(TreeNode *root,int index,vector<int> &nums,bool left){
//         int n = nums.size();
//         if(index<0 || index>=n)return;
        
//         root = new TreeNode(nums[index]);
//         if(left) build(root->left,index-1,nums,left);
//         else build(root->right,index+1,nums,left);
//     }
    
//     TreeNode* sortedArrayToBST(vector<int>& nums) {
//         int n = nums.size();
//         TreeNode *root = new TreeNode(nums[n/2]);
//         int left = n/2-1;
//         int right = n/2+1;
        
//         build(root->left,left,nums,true);
//         build(root->right,right,nums,false);
        
//         return root;
//     }
    
    
    
    
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if(num.size() == 0) return NULL;
        if(num.size() == 1)
        {
            return new TreeNode(num[0]);
        }
        
        int middle = num.size()/2;
        TreeNode* root = new TreeNode(num[middle]);
        
        vector<int> leftInts(num.begin(), num.begin()+middle);
        vector<int> rightInts(num.begin()+middle+1, num.end());
        
        root->left = sortedArrayToBST(leftInts);
        root->right = sortedArrayToBST(rightInts);
        
        return root;
    }
};