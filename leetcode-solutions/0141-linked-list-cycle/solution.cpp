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
    bool hasCycle(ListNode *head) {
        ListNode* mover=head;
        while(mover!=nullptr){
            mover->val=INT_MIN;
            mover=mover->next;
            if(mover==nullptr)return false;
            if(mover->val==INT_MIN) return true;
        }
        return false;
    }
};
