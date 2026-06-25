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
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> arr= new ArrayList<>();
        if(root==null)return arr;
        Queue<TreeNode> q= new LinkedList<>();
        q.offer(root);
        while(!q.isEmpty()){
            List<Integer> temp = new ArrayList<>();
            int len=q.size();
            for(int i=0;i<len;i++){
                TreeNode front=q.poll();
                if(front.left!=null)q.offer(front.left);
                if(front.right!=null)q.offer(front.right);
                temp.add(front.val);
            }
            arr.add(temp);
        }
        return arr;

    }
}
