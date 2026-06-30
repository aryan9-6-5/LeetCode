class Solution {
public:
    int help(TreeNode* root, int curr) {
        if (!root) return 0;

        curr = curr * 10 + root->val;

        if (!root->left && !root->right)
            return curr;

        return help(root->left, curr) + help(root->right, curr);
    }

    int sumNumbers(TreeNode* root) {
        return help(root, 0);
    }
};
