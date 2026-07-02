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
    void reverseseg(ListNode* start,ListNode* end){
        ListNode* prev=nullptr;
        ListNode* curr=start;
        ListNode* stop=end->next;
        while(curr!=stop){
            ListNode* nextnode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextnode;
        }
    }
    ListNode*findk(ListNode* head,int k){
        ListNode* curr=head;
        for(int i=1;i<k;i++){
            if(curr==nullptr)return nullptr;
            curr=curr->next;
        }
        return curr;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr || k==1)return head;
        ListNode* prev=nullptr;
        ListNode* mover=head;
        while(mover!=nullptr){
            ListNode* knode=findk(mover,k);
            if(knode==nullptr) break;
            ListNode* nextGroup=knode->next;
            reverseseg(mover,knode);
            if(prev==nullptr)head=knode;
            else prev->next=knode;
            mover->next=nextGroup;
            prev=mover;
            mover=nextGroup;
        }
        return head;
    
    }
};