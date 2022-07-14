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
    ListNode* reverse(ListNode* head,ListNode* last){
        ListNode* prev=NULL;
        while(head!=last){
            auto temp=head->next;
            head->next=prev;
            prev=head;
            head=temp;
        }
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto ptr=head;
        for(int i=0 ; i<k ; i++){
            if(!ptr)return head;
            ptr=ptr->next;
        }
        auto nhead=reverse(head,ptr);
        head->next=reverseKGroup(ptr,k);
        return nhead;
    }
};