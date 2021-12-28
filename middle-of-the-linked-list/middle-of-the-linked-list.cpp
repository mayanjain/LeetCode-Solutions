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
    int total;
    ListNode* ans;
    
    void count(int cnt,ListNode* head){
        if(!head){
            total=cnt;
            return;
        }
        count(cnt+1,head->next);
        if(cnt==total/2)ans=head;
    }
    
    ListNode* middleNode(ListNode* head) {
        count(0,head);
        return ans;   
    }
};