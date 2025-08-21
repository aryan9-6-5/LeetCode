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
    void reorderList(ListNode* head) {
        ListNode* mid=middleNode(head);
        ListNode* t1= head;
        ListNode* t2=mid->next;
        mid->next=NULL;
        t2=reverseList(t2);
        ListNode* t;
        while(t2){
            t=t1->next;
            t1->next=t2;
            t1=t2;
            t2=t;
        }
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr != NULL) {
            ListNode* nextNode = curr->next; 
            curr->next = prev;               
            prev = curr;                    
            curr = nextNode;                 
        }
        return prev;
    }
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;          
            fast = fast->next->next;    
        }
        return slow;
    }    
};
