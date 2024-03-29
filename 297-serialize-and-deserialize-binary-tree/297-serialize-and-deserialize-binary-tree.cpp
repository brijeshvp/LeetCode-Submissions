/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        if(!root)return s;
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            
            if(node) s+= (to_string(node->val) + ",");
            else s+= "#,";
            
            if(node != NULL){
               q.push(node->left);
               q.push(node->right);            
           }
        }
        
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)return NULL;
        
        stringstream s(data);
        
        string tmp;
        getline(s,tmp,',');     // get the string from stringstream s to tmp string until delimeter = ,(comma)
        TreeNode* root = new TreeNode(stoi(tmp));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            
            string left,right;
            getline(s,left,',');
            getline(s,right,',');
            
            if(left=="#") node->left = NULL;
            else{
                TreeNode* l = new TreeNode(stoi(left));
                node->left = l;
                q.push(l);
            }
            
            if(right=="#") node->right = NULL;
            else{
                TreeNode* r = new TreeNode(stoi(right));
                node->right = r;
                q.push(r);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));