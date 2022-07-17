/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         // approach-1 : using extra space TC: O(m+n) and SC: O(m)
//         if(!headA || !headB)return NULL;
        
//         map<ListNode*,int> mp;
//         ListNode* temp = headA;
//         while(temp){
//             mp[temp] = 1;
//             temp = temp->next;
//         }
        
//         temp = headB;
//         while(temp){
//             if(mp.find(temp)!=mp.end())return temp;
//             temp = temp->next;
//         }
//         return NULL;
        
        
        
        // approach-2 : without extra space TC: O(m+n) and SC: O(1)
        // why else case -> think this Test case: LL1: 3 and LL2: 2->3
        ListNode *a = headA, *b = headB;
        while(a!=b){
            if(a==NULL)a = headB;
            else a = a->next;
            
            if(b==NULL)b = headA;
            else b = b->next;
        }
        
        return a;
    }
};