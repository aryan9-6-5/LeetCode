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
    vector<TreeNode*> tree;
    void dfs(TreeNode* root){
        if(root==nullptr)return;
        tree.push_back(root);
        if(root->left!=nullptr)dfs(root->left);
        if(root->right!=nullptr)dfs(root->right);
    }
    void flatten(TreeNode* root) {
        dfs(root);
        TreeNode* mover=root;
        for(int i=1;i<tree.size();i++){
            mover->left=nullptr;
            mover->right=tree[i];
            mover=mover->right;
        }
    }

};
