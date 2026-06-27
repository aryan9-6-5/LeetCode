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
    int maxH=0;
    public int maxHeight(TreeNode root){
        if(root==null)return 0;
        int left=maxHeight(root.left);
        int right=maxHeight(root.right);
        maxH=Math.max(left+right,maxH);
        return 1+Math.max(left,right);
    }
    public int diameterOfBinaryTree(TreeNode root) {
        maxHeight(root);
        return maxH;
    }
}
