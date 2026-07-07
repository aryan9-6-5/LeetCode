/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s="";
        if(root==nullptr)return s;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(curr==nullptr) s.append("#,");
            else s.append(to_string(curr->val)+',');
            if(curr!=nullptr){
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return s;
    }

    TreeNode* deserialize(string data) {
        if(data.size()==0)return nullptr;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            getline(s,str,',');
            if(str=="#")curr->left=nullptr;
            else{
                TreeNode* newNode=new TreeNode(stoi(str));
                curr->left=newNode;
                q.push(newNode);
            }
            getline(s,str,',');
            if(str=="#")curr->right=nullptr;
            else{
                TreeNode* newNode=new TreeNode(stoi(str));
                curr->right=newNode;
                q.push(newNode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));