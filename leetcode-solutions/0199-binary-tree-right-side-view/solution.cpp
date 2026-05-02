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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root==nullptr)return ans;
        queue<pair<TreeNode*,int>>q;//Node, position
        map<int,int> level;//position, node value
        q.push({root,0});
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            TreeNode* mover=p.first;
            int position=p.second;
            if(level.find(position)==level.end()){
                level[position]=mover->val;
            }
            else level[position]=mover->val;
            if(mover->left)q.push({mover->left,position+1});
            if(mover->right)q.push({mover->right,position+1});
        }
        for(auto i:level){
            ans.push_back(i.second);
        }
        return ans;
    }
};
