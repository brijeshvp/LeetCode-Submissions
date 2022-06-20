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
        ListNode *p = NULL, *c = head, *n = head->next;
        
        while(c!=NULL){
            c->next = p;
            p = c;
            c = n;
            if(n!=NULL)n = n->next;
        }
        return p;
    }
        
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
        
        // Creating a dummy node to avoid adding checks for the first node
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode *prevToStart = dummy;
        ListNode *start = head;
        
        // Loop to determine the lengths of groups
        for(int len = 1;len<=1e5 && start!=NULL ;++len){
            ListNode *end = start;
            
            // Determining the length of the current group(denoted [start,end])
            // Its maximum length can be equal to len
            int dist = 1;
            while(dist<len && end->next!=NULL){
                dist++;
                end = end->next;
            }
            
            // Head of the next group
            ListNode *nextStart = end -> next;
            
            if((dist % 2) == 0) {
                // If even sized group is found
                // Reversing the group and setting prev and head appropriately
                end -> next = NULL; // to reverse from start to end
                prevToStart -> next = reverse(start);
                start -> next = nextStart;
                prevToStart = start;
                start = nextStart;
            } else {
                // If group is odd sized, then simply going towards the next group
                prevToStart = end;
                start = nextStart;
            }
        }
        
        // Returning the head
        return dummy -> next;
    }
};