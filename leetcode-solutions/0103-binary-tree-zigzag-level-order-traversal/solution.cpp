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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        bool flag=0;
        if(root==nullptr)return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            vector<int> level;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                level.push_back(node->val);
                q.pop();
            }
            if(flag==0)flag=1;
            else{
                reverse(level.begin(),level.end());
                flag=0;
            }
            ans.push_back(level);
        }
        return ans;
    }
};
