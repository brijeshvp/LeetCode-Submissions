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
    ListNode* getLeftMid(ListNode *head){
        ListNode *slow = head, *fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    ListNode* merge(ListNode *left, ListNode *right){
        if(left==NULL)return right;
        if(right==NULL)return left;
        
        ListNode *dummy = new ListNode(-1);
        ListNode *tail = dummy;
        
        while(left!=NULL && right!=NULL){
            if(left->val < right->val){
                tail->next = left;
                tail = tail->next;
                left = left->next;
            }
            else{
                tail->next = right;
                tail = tail->next;
                right = right->next;
            }
        }
        
        if(left)tail->next = left;
        if(right)tail->next = right;
        
        return dummy->next;
    }
    
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
        
        ListNode *left = head;
        ListNode *right = getLeftMid(head);
        ListNode *tmp = right->next;
        right->next = NULL;
        right = tmp;
        
        left = sortList(left);
        right = sortList(right);
        
        return merge(left,right);   // merge two sorted lists(already done this question)
    }
};