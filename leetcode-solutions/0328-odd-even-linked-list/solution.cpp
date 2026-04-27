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
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr || head->next==nullptr)return head;
        ListNode* first=head;
        ListNode* second=first->next;
        ListNode* temp=second;
        while(second!=nullptr && second->next!=nullptr){
            first->next=first->next->next;
            first=first->next;
            second->next=second->next->next;
            second=second->next;
        }
        first->next=temp;
        return head;
    }
};
