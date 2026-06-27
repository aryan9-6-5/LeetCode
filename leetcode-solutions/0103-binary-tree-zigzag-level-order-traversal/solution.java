/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> ans=new ArrayList<>();
        if(root==null)return ans;
        Queue<TreeNode> q=new LinkedList<>();
        q.offer(root);
        boolean flag=true;
        while(!q.isEmpty()){
            List<Integer> temp=new ArrayList<>();
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode t=q.poll();
                if(t.left!=null)q.offer(t.left);
                if(t.right!=null)q.offer(t.right);
                if(flag) temp.addLast(t.val);
                else temp.addFirst(t.val);
            }
            ans.add(temp);
            flag=!flag;
        }
        return ans;
    }
}
