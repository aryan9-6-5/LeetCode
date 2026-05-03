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
    bool isLeaf(TreeNode* node) {
        return !node->left && !node->right;
    }
    void preorder(TreeNode* root,string temp,vector<string>& ans){
        if(root==nullptr)return;
        temp+=to_string(root->val);
        if(isLeaf(root))ans.push_back(temp);
        else {
            temp+="->";
            preorder(root->left,temp,ans);
            preorder(root->right,temp,ans);
        }
        temp.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string temp;
        vector<string>s;
        if(root==nullptr)return s;
        preorder(root,temp,s);
        return s;
    }
};
