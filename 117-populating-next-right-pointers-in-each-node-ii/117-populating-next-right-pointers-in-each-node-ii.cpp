/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/


 //     0
 //   2     4
 //  1    3  -1
 // 5 1    6    8
// class Solution {
// public:
//     Node* connect(Node* root) {
//         if(root==NULL)return root;
        
//         queue<Node*> q;
//         q.push(root);
        
//         queue<Node*> temp;
//         while(!q.empty()){
//             temp = q;
//             for(int i=0;i<temp.size();++i){
//                 Node* t = temp.front();
//                 temp.pop();
                
//                 if(temp.size()>0)t->next = temp.front();
//             }
            
//             int sz = q.size();
//             while(sz--){
//                 Node* node1 = q.front();
//                 q.pop();
                
//                 if(node1->left)q.push(node1->left);
//                 if(node1->right)q.push(node1->right);
                
//             }
//         }
//         return root;
//     }
// };
         
         
         
class Solution {
public:
    Node* connect(Node* root) 
    {
        if (!root)
            return root;
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        while (q.size() > 1)
        {
            Node* curr = q.front();
            q.pop();
            if (!curr)
            {
                q.push(NULL);
                continue;
            }
            curr->next = q.front();
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        return root;
    }
};