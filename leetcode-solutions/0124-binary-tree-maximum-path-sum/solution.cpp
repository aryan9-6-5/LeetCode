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
    int maxdepth(TreeNode* root,int& maxi){
        if(root==nullptr)return 0;
        int lh=maxdepth(root->left,maxi);
        lh=max(lh,0);
        int rh=maxdepth(root->right,maxi);
        rh=max(rh,0);
        maxi=max(maxi,root->val+lh+rh);
        return root->val+max(lh,rh);
    }
    int maxPathSum(TreeNode* root) {
        int maxi=-1001;
        maxdepth(root,maxi);
        return maxi;
    }
};
