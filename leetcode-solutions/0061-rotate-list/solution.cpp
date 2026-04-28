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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* mover=head;
        int count=1;
        while(mover->next!=nullptr){
            mover=mover->next;
            count++;
        }
        k = k % count;
        if(k == 0) return head;
        mover->next=head;
        mover=head;
        int req=count-k;
        for(int i=1;i<req;i++){
            mover=mover->next;
        }
        head=mover->next;
        mover->next=nullptr;
        return head;
    }
};
