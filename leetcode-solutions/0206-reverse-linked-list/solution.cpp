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
    ListNode* convert(vector<int> arr) {
        if (arr.empty()) return nullptr;
        int n = arr.size();
        ListNode* newHead = new ListNode(arr[n-1]);
        ListNode* mover = newHead;

        for (int i = n - 2; i >= 0; i--) {
            ListNode* temp = new ListNode(arr[i]);
            mover->next = temp;
            mover = temp;
        }
        return newHead;
    }
    ListNode* reverseList(ListNode* head) {
        vector<int> ans;
        ListNode* mover=head;
        while(mover != nullptr){
            ans.push_back(mover->val);
            mover=mover->next;
        }
        return convert(ans);
    }
};
