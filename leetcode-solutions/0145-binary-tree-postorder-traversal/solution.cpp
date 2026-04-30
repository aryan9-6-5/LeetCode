/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root==nullptr)return ans;
        TreeNode* curr=root;
        TreeNode* prev=nullptr;
        stack<TreeNode*>st;
        while(curr!=nullptr || !st.empty()){
            if(curr!=nullptr){
                st.push(curr);
                curr=curr->left;
            }
            else{
                curr=st.top();
                if(curr->right==nullptr || curr->right==prev){
                    ans.push_back(curr->val);
                    st.pop();
                    prev=curr;
                    curr=nullptr;
                }
                else curr=curr->right;
            }
        }
        return ans;
    }
};
