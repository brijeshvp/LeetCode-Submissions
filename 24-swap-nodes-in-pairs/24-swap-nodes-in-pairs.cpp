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
    void reverse(ListNode *s,ListNode *e){
        ListNode *p=NULL, *c=s, *n=s->next;
        while(p!=e){
            c->next=p;
            p=c;
            c=n;
            if(n!=NULL)n=n->next;
        }
    }

    ListNode* swapPairs(ListNode* head) {
        int k = 2;
        // BC
        if(head==NULL || head->next==NULL || k==1)return head;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *beforeS=dummy, *e=head;

        int i=0;
        while(e!=NULL){
            i++;
            if(i%k==0){
                ListNode *s = beforeS->next, *temp = e->next;
                reverse(s,e);

                beforeS->next = e;
                s->next = temp;

                beforeS = s;
                e = temp;
            }
            else{
                e=e->next;
            }
        }
        return dummy->next;
    }
};