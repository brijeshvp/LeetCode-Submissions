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
    ListNode* partition(ListNode* head, int x) {
        ListNode *dummy1 = new ListNode(-1);
        ListNode *dummy2 = new ListNode(-1);
        
        ListNode *tail1 = dummy1, *tail2 = dummy2, *temp = head;
        while(temp!=NULL){
            if(temp->val < x){
                tail1->next = temp;
                tail1 = tail1->next;
            }
            else{
                tail2->next = temp;
                tail2 = tail2->next;
            }
            temp = temp->next;
        }
        
        tail1->next = dummy2->next;
        tail2->next = NULL;
        
        return dummy1->next;
    }
};