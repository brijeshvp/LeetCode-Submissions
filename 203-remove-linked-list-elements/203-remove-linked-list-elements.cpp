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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL)return NULL;
        
        ListNode *dummy = new ListNode(-1);
        ListNode *tail = dummy;
        dummy->next = head;
        
        while(tail->next!=NULL){
            if(tail->next->val == val){
                ListNode *toDel = tail->next;
                tail->next = toDel->next;
                delete toDel;
            }
            else tail = tail->next;
        }
        return dummy->next;
    }
};