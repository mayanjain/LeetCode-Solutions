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
    
    ListNode* solve(ListNode* l1,ListNode* l2){
        if(!l1)return l2;
        if(!l2)return l1;
        ListNode* root=new ListNode();
        if(l1->val<l2->val){
            root->val=l1->val;
            root->next=solve(l1->next,l2);
        }
        else{
            root->val=l2->val;
            root->next=solve(l2->next,l1);
        }
        return root;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(!lists.size())return NULL;
        if(lists.size()==1)return lists[0];
        int i=0,n=lists.size();
        vector<ListNode*> nlist;
        for(i ; i<n-1 ; i+=2){
            nlist.push_back(solve(lists[i],lists[i+1]));
        }
        if(i!=n){
            nlist.push_back(lists[n-1]);
        }
        return mergeKLists(nlist);
    }
};