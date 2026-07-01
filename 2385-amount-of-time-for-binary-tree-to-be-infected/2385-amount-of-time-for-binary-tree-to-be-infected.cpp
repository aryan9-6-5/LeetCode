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
//parent pointer map and find resultant node level order traversal
//create a visited map and check size and perform buring
class Solution {
public:
    unordered_map<TreeNode*,TreeNode*> map;
    TreeNode* parentMap(TreeNode* root,int start){
        if(root==nullptr)return root;
        TreeNode* target=nullptr;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->val==start)target=curr;
                if(curr->left!=nullptr){
                    map[curr->left]=curr;
                    q.push(curr->left);
                }
                if(curr->right!=nullptr){
                    map[curr->right]=curr;
                    q.push(curr->right);
                }                
            }
        }
        return target;
    }
    int reqTime(TreeNode* target){
        if(target==nullptr)return 0;
        queue<TreeNode*>q;
        unordered_map<TreeNode*,bool>visited;
        q.push(target);
        visited[target]=1;
        int ans=0;
        while(!q.empty()){
            int flag=0;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* curr=q.front();
                q.pop();
                visited[curr]=1;
                if(curr->left && !visited[curr->left]){
                    visited[curr->left]=1;
                    q.push(curr->left);
                    flag=1;
                }
                if(curr->right && !visited[curr->right]){
                    visited[curr->right]=1;
                    q.push(curr->right);
                    flag=1;
                }
                if(map.count(curr) && !visited[map[curr]]){
                    visited[map[curr]]=1;
                    q.push(map[curr]);
                    flag=1;
                }
            }
            if(flag==1)ans+=1;
        }
        return ans;
    }
    int amountOfTime(TreeNode* root, int start) {
        TreeNode* target=parentMap(root,start);
        return reqTime(target);
    }
};