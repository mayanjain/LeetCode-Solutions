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
    bool hasCycle(ListNode *head) {
        if(!head || !head->next)return 0;
        auto ptr=head;
        while(head->next && head->next->next){
            ptr=ptr->next;
            head=head->next->next;
            if(ptr==head)return 1;
        }
        return 0;
    }
};