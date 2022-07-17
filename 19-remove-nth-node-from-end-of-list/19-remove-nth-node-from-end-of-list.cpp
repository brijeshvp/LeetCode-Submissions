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
    int length(ListNode *head){
        int len = 0;
        ListNode *temp = head;
        while(temp){
            len++;
            temp = temp->next;
        }
        return len;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL)return head;
        int l = length(head);
        if(n>l)return head;
        
        int target = l-n;
        ListNode *dummy = new ListNode(-1);
        ListNode *tail = dummy;
        tail->next = head;
        
        while(target--){
            tail = tail->next;
        }
        
        ListNode *toDel = tail->next;
        tail->next = toDel->next;
        return dummy->next;
    }
};