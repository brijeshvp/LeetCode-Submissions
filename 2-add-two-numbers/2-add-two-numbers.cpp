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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL)return l2;
        if(l2==NULL)return l1;
        
        ListNode *p1 = l1, *p2 = l2;
        ListNode *dummy = new ListNode(-1);
        ListNode *tail = dummy;
        int carry = 0;
        while(p1!=NULL && p2!=NULL){
            int sum = p1->val + p2->val + carry;
            ListNode *node = new ListNode(sum%10);
            tail->next = node;
            tail = tail->next;
            carry = sum/10;
            p1 = p1->next;
            p2 = p2->next;
        }
        
        while(p1!=NULL){
            int sum = p1->val + carry;
            ListNode *node = new ListNode(sum%10);
            tail->next = node;
            tail = tail->next;
            carry = sum/10;
            p1 = p1->next;
        }
        
        while(p2!=NULL){
            int sum = p2->val + carry;
            ListNode *node = new ListNode(sum%10);
            tail->next = node;
            tail = tail->next;
            carry = sum/10;
            p2 = p2->next;
        }
        
        if(carry!=0){
            ListNode *node = new ListNode(carry);
            tail->next = node;
        }
        return dummy->next;
    }
};