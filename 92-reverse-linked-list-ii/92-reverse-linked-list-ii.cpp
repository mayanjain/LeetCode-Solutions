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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right)return head;
        auto dummy=new ListNode(0);
        dummy->next=head;
        auto cur=dummy;
        while(left>1){
            cur=cur->next;
            right--;
            left--;
        }
        auto prev=cur;
        cur=cur->next;
        while(right-->1){
            auto third=cur->next;
            cur->next=third->next;
            third->next=prev->next;
            prev->next=third;
        }
        auto res=dummy->next;
        delete(dummy);
        return res;
    }
};