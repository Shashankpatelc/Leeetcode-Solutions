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

    long product = 0;
    long total_sum = 0;

    public void all_sum(TreeNode node) {

        if ( node.left != null ) all_sum(node.left);
        if ( node.right != null ) all_sum(node.right);
        
        total_sum += node.val;
    }
    
    
    public long dfs(TreeNode node) {

        if (node == null) return 0;

        long left = 0;
        long right = 0;

        if ( node.left != null ) left = dfs(node.left);
        if ( node.right != null ) right = dfs(node.right);

        long sum = left + right + node.val;
        long cur_prdt = ( total_sum - sum ) * ( sum );  

        if ( cur_prdt > product ) {
            product = cur_prdt;
        }

        return sum;
    }

    public int maxProduct(TreeNode root) {

        product = 0;
        total_sum = 0;
        
        all_sum(root);
        dfs(root);   

        return (int) (product % 1000000007);    
    }
}