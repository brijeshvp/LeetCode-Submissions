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
    ListNode* middle(ListNode *head){
        ListNode *slow = head, *fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL)return NULL;
        
        ListNode *toDel = middle(head);
        
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *tail = dummy;
        
        while(tail->next!=NULL){
            if(tail->next == toDel){
                tail->next = toDel->next;
                delete toDel;
            }
            else tail = tail->next;
        }
        return dummy->next;
    }
};