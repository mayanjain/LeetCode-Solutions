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
    ListNode *getIntersectionNode(ListNode *h1, ListNode *h2) {
        int sa=0,sb=0;
        auto p1=h1,p2=h2;
        while(p1){
            sa++;
            p1=p1->next;
        }
        while(p2){
            sb++;
            p2=p2->next;
        }
        if(sa<sb)swap(h1,h2);
        p1=h1,p2=h2;
        auto cur=abs(sa-sb);
        while(p1){
            if(p1==p2)return p1;
            p1=p1->next;
            if(cur<=0)p2=p2->next;
            cur--;
        }
        return NULL;
    }
};