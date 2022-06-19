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
    ListNode* reverse(ListNode *head){
        if(head==NULL)return NULL;
        
        ListNode *p = NULL, *c = head, *n = head->next;
        while(c!=NULL){
            c->next = p;
            p = c;
            c = n;
            if(n!=NULL)n = n->next;
        }
        return p;
    }
    
    bool isPalindrome(ListNode* head) {
        if(head==NULL)return true;
        
        ListNode *slow = head, *fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        slow->next = reverse(slow->next);
        
        ListNode *p1 = head, *p2 = slow->next;
        while(p2!=NULL){
            if(p1->val != p2->val)return false;
            
            p1 = p1->next;
            p2 = p2->next;
        }
        
        slow->next = reverse(slow->next);
        return true;
    }
};