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
        if(head==NULL || head->next==NULL)return head;  // nothing to reverse
        
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode *end = dummy, *prevToStart = dummy;
        int dist1 = left - 1;    // start is at dist left from dummy, then prevToStart will be at dist left-1 from dummy(obvious)
        while(prevToStart!=NULL && dist1--){
            prevToStart = prevToStart->next;
        }
        ListNode *start = prevToStart->next;
        
        int dist2 = right;  // end will be at dist right from dummy
        while(end!=NULL && dist2--){
            end = end->next;
        }
        
        ListNode *nextToEnd = end->next;    // save, so that after reversal start becomes new end so it can point to nextToEnd.
        prevToStart->next = reverse(start,end); // end becomes new start after reversal, so prevToStart can point to it
        start->next = nextToEnd;
        
        return dummy->next;
    }
};