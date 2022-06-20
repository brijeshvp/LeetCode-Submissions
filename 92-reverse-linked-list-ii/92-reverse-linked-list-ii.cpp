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
    ListNode* reverse(ListNode *l, ListNode *r){
        ListNode *p = NULL, *c = l, *n = l->next;
        
        while(p!=r){
            c->next = p;
            p = c;
            c = n;
            if(n!=NULL)n = n->next;
        }
        return p;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL || head->next==NULL)return head;
        
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode *tail1 = dummy, *tail2 = dummy, *prevToTail1 = dummy;
        int dist1 = left - 1, dist2 = right;
        while(prevToTail1!=NULL && dist1--){
            prevToTail1 = prevToTail1->next;
        }
        tail1 = prevToTail1->next;
        
        while(tail2!=NULL && dist2--){
            tail2 = tail2->next;
        }
        
        ListNode *afterTail2 = tail2->next;
        prevToTail1->next = reverse(tail1,tail2);
        tail1->next = afterTail2;
        
        return dummy->next;
    }
};