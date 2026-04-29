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
    ListNode* detect(ListNode* slow,ListNode* fast){
        while(fast!=slow){
            fast=fast->next;
            slow=slow->next;
        }
        return slow;
    }
    ListNode *detectCycle(ListNode *head) {
        if(head==nullptr || head->next==head) return head;
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=nullptr && fast->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow){
                slow=head;
                return detect(slow,fast);
            }
        }
        return nullptr;
    }
};
