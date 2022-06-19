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
    ListNode* insertionSortList(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
        
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *tail = dummy;
        tail = tail->next;
        
        while(tail->next!=NULL){
            if(tail->next->val < tail->val){
                ListNode *toDel = tail->next;
                int value = toDel->val;
                tail->next = toDel->next;
                delete toDel;
                
                ListNode *temp = dummy;
                while(temp->next!=NULL && temp->next->val <= value)temp = temp->next;
                if(temp->next!=NULL && temp->next->val > value){
                    ListNode *node = new ListNode(value);
                    node->next = temp->next;
                    temp->next = node;
                }
            }
            else tail = tail->next;
        }
        return dummy->next;
    }
};