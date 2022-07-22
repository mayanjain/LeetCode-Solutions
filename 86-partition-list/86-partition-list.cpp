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
    ListNode* partition(ListNode* head, int x) {
        vector<int> v;
        int k=0,z=0;
        while(head){
            if(head->val<x)k++;
            v.push_back(head->val);
            head=head->next;
        }
        vector<int> res(v.size());
        for(auto& i:v){
            if(i<x)res[z++]=i;
            else res[k++]=i;
        }
        ListNode* ans=new ListNode(0),*ptr=ans;
        for(auto& i:res){
            ans->next=new ListNode(i);
            ans=ans->next;
        }
        return ptr->next;
    }
};