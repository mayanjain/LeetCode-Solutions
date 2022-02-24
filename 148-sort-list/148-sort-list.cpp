class Solution {
public:
    ListNode* midPoint(ListNode* head){
        ListNode* ptr=NULL;
        while(head && head->next){
            if(!ptr)ptr=head;
            else ptr=ptr->next;
            head=head->next->next;
        }
        auto mid=ptr->next;
        ptr->next=NULL;
        return mid;
    }
    
    ListNode* merge(ListNode* first,ListNode* second){
        ListNode head(0);
        ListNode* ptr=&head;
        while(first && second){
            if(first->val<second->val){
                ptr->next=first;
                first=first->next;
            }
            else {
                ptr->next=second;
                second=second->next;
            }
            ptr=ptr->next;
        }
        if(first) ptr->next=first;
        else ptr->next=second;
        return head.next;
    }
    
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)return head;
        auto mid=midPoint(head);
        auto first=sortList(head);
        auto second=sortList(mid);
        return merge(first,second);
    }
};