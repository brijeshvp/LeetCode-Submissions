/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* getLeftMiddle(ListNode *head){
        ListNode *slow = head, *fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode* reverse(ListNode *head){
        ListNode *p = NULL, *c = head, *n = head->next;
        
        while(c!=NULL){
            c->next = p;
            p = c;
            c = n;
            if(n!=NULL)n = n->next;
        }
        return p;
    }

    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL)return;
        
        ListNode *tmp = getLeftMiddle(head);
        ListNode *left = head;
        ListNode *right = tmp->next;
        tmp->next = NULL;
        
        // reverse right half
        right = reverse(right);
        
        while(left!=NULL && right!=NULL){
            ListNode *nextToLeft = left->next, *nextToRight = right->next;
            
            left->next = right;
            right->next = nextToLeft;
            
            left = nextToLeft;
            right = nextToRight;
        }
    }
};