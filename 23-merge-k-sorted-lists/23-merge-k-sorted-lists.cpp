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



class comp{
    public:
        bool operator() (ListNode *a,ListNode *b){
            // return a->val < b->val;  // this will be max heap
            return a->val > b->val;     // this will be min heap
        }
};

class Solution {
public:
    // this comparator function will not work for heaps(we have to pass comparator class for it)
    bool cmp(ListNode *a,ListNode *b){
        // return a->val < b->val;  // this will be max heap
        return a->val > b->val;     // this will be min heap
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // approach-4 -> using min heap
        priority_queue<ListNode*,vector<ListNode*>,comp> pq;
        for(auto it : lists){
            if(it!=NULL)pq.push(it);
        }
        
        
        ListNode *dummy = new ListNode(-1);
        ListNode *tail = dummy;
        
        while(!pq.empty()){
            ListNode* temp = pq.top();
            pq.pop();
            
            tail->next = temp;
            tail = temp;
            
            if(temp->next!=NULL)pq.push(temp->next);
        }
        return dummy->next;
    }
};