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
    ListNode* cur;
    bool check(ListNode* head){
        if(head==NULL)return true;
        bool ok = check(head->next);
        if(cur->val!=head->val)return false;
        cur=cur->next;
        return ok;
    }
    
    bool isPalindrome(ListNode* head) {
        cur=head;
        return check(head);
    }
};