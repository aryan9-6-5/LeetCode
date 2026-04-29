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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans=new ListNode(-101);
        ListNode* t=ans;
        ListNode* a=list1;
        ListNode* b=list2;
        while(a!=nullptr && b!=nullptr){
            if(a->val<b->val){
                t->next=a;
                t=a;
                a=a->next;
            }
            else{
                t->next=b;
                t=b;
                b=b->next;
            }
        }
        if(a!=nullptr){
            t->next=a;
        }
        if(b!=nullptr){
            t->next=b;
        }
        return ans->next;
    }
};
