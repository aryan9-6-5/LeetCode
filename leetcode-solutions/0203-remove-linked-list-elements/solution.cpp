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
    ListNode* removeElements(ListNode* head, int val) {
        while (head != nullptr && head->val == val) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
        if(head==nullptr) return nullptr;
        ListNode* mover=head->next;
        ListNode* prev=head;
        while(mover!=nullptr){
            if(mover->val==val){
                prev->next=mover->next;
                delete mover;
                mover=prev->next;
            }
            else{
                prev=mover;
                mover=mover->next;
            }
        }
        return head;
    }
};
