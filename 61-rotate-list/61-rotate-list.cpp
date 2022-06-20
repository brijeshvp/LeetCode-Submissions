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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return head;
        
        ListNode *tail = head;
        int len=1; // number of nodes
        while(tail->next!=NULL)  // get the number of nodes in the list
        {
            len++;
            tail = tail->next;
        }
        tail->next = head; // circle the link

        // if rotation is required
        if(k %= len) 
        {
            for(auto i=0; i<len-k; i++) tail = tail->next; // the tail node is the (len-k)-th node (1st node is head)
        }
        
        ListNode *newH = tail->next; 
        tail->next = NULL;
        return newH;
    }
};