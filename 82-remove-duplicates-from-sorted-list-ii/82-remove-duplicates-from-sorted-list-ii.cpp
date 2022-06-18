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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;  // no duplicates
        
        map<int,int> mp;
        ListNode *temp = head;
        while(temp!=NULL){
            mp[temp->val]++;
            temp = temp->next;
        }
        
        ListNode *dummy = new ListNode(-1);
        ListNode *tail = dummy;
        tail->next = head;
        
        while(tail->next!=NULL){
            if(mp[tail->next->val]>1){
                ListNode *toDel = tail->next;
                tail->next = toDel->next;
                delete toDel;
            }
            else tail = tail->next;
        }
        return dummy->next;
    }
};