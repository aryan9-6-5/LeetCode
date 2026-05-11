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
    int maxdepth(TreeNode* root,int& totmax){
        if(root==nullptr)return 0;
        int lh=maxdepth(root->left,totmax);
        int rh=maxdepth(root->right,totmax);
        int curdia=lh+rh;
        totmax=max(totmax,curdia);
        return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr)return 0;
        int totmax=0;
        maxdepth(root,totmax);
        return totmax;
    }
};
