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
    public int maxHeight(TreeNode root){
        if(root==null)return 0;
        int left=maxHeight(root.left);
        if(left==-1)return -1;
        int right=maxHeight(root.right);
        if(right==-1)return -1;
        if(Math.abs(right-left)>1)return -1;
        return 1+Math.max(left,right);
    }
    public boolean isBalanced(TreeNode root) {
        if(maxHeight(root)!=-1)return true;
        return false;
    }
}
