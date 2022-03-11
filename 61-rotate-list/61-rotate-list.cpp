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
        if(!head || !head->next)return head;
        int n=0;
        auto ptr=head,mergnode=head;
        while(ptr){
            n++;
            ptr=ptr->next;
        }
        k%=n;
        if(k==0)return head;
        k=n-k-1;
        ptr=head;
        while(k--)ptr=ptr->next;
        head=ptr->next;
        ptr->next=NULL;
        ptr=head;
        while(ptr->next)ptr=ptr->next;
        ptr->next=mergnode;
        return head;
    }
};