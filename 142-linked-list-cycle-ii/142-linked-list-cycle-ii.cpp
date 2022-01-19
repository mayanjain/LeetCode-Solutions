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
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next)return NULL;
        auto slow=head,fast=head;
        bool cycle=0;
        while(slow!=NULL && fast!=NULL){
            slow=slow->next;
            if(fast->next==NULL)return NULL;
            fast=fast->next->next;
            if(fast==slow){cycle=1;break;}
        }  
        if(!cycle)return NULL;
        fast=head;
        while(fast!=slow){
            fast=fast->next;
            slow=slow->next;
        }
        return fast;
    }
};