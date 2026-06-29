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
    vector<int>ans;
    void fillAns(TreeNode* root,int level){
        if(root==nullptr)return;
        if(level==ans.size())ans.push_back(root->val);
        if(root->right!=nullptr)fillAns(root->right,level+1);
        if(root->left!=nullptr)fillAns(root->left,level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        fillAns(root,0);
        return ans;
    }
};
