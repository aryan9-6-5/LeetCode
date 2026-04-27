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
    bool isPalindrome(ListNode* head) {
        stack<int> stack;
        ListNode* mover=head;
        while(mover!=nullptr){
            stack.push(mover->val);
            mover=mover->next;
        }
        mover=head;
        while(mover!=nullptr){
            if(mover->val!=stack.top())return false;
            stack.pop();
            mover=mover->next;
        }
        if(stack.empty())return true;
        return false;
    }
};
