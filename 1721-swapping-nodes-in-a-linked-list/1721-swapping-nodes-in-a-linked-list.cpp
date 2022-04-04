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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* p1=NULL,*p2=NULL;
        for(auto ptr=head ; ptr!=NULL ; ptr=ptr->next){
            p2=p2==NULL?p2:p2->next;
            if(--k==0){
                p1=ptr;
                p2=head;
            }
        }
        swap(p1->val,p2->val);
        return head;
    }
};