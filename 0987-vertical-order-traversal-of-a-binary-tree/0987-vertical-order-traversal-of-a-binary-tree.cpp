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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==nullptr)return ans;
        queue<pair<TreeNode*,pair<int,int>>>q;// Node, Xaxis, Yaxis
        map<int,map<int,multiset<int>>>hash;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto m=q.front();
            q.pop();
            TreeNode* mover=m.first;
            int x=m.second.first;
            int y=m.second.second;
            hash[x][y].insert(mover->val);
            if(mover->left){
                q.push({mover->left,{x-1,y+1}});
            }
            if(mover->right){
                q.push({mover->right,{x+1,y+1}});
            }
        }
        for(auto& x: hash){
            vector<int>coloumn;
            for(auto y:x.second){
                coloumn.insert(coloumn.end(),y.second.begin(),y.second.end());
            }
            ans.push_back(coloumn);
        }
        return ans;
    }
};