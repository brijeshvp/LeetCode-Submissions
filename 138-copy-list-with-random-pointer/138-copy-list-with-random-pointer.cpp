/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*,Node*> copies;
        
        Node *temp = head;
        while(temp!=NULL){
            Node *copy = new Node(temp->val);
            copies[temp] = copy;
            temp = temp->next;
        }
        
        temp = head;
        while(temp!=NULL){
            copies[temp]->next = copies[temp->next];
            copies[temp]->random = copies[temp->random];
            temp = temp->next;
        }
        return copies[head];
    }
};