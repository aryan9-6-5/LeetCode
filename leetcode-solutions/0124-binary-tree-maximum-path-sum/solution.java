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
    int maxi=Integer.MIN_VALUE;
    public int height(TreeNode root){
        if(root==null)return 0;
        int left=height(root.left);
        if(left<0)left=0;
        int right=height(root.right);
        if(right<0)right=0;
        maxi=Math.max(root.val+left+right,maxi);
        return root.val+Math.max(left,right);
    }
    public int maxPathSum(TreeNode root) {
        height(root);
        return maxi;
    }
}
