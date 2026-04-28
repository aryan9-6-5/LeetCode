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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* mover=head;
        ListNode* ans=new ListNode(-101);
        ListNode* newHead=ans;
        while(mover!=nullptr){
            if(mover->val>newHead->val){
                newHead->next=mover;
                newHead=mover;
            }
            mover=mover->next;
        }
        newHead->next=nullptr;
        return ans->next;
    }
};
