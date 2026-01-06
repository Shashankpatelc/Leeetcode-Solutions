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
    public int maxLevelSum(TreeNode root) {
        int level = 1, max_level = 1, max_sum = Integer.MIN_VALUE;
        
        TreeNode node;
        Deque<TreeNode> queue= new ArrayDeque<>();

        queue.add(root);

        while ( !queue.isEmpty() ) {

            int len = queue.size();
            int sum = 0;
            
            for( int i = 0; i < len; i++ ) {
                
                node = queue.poll();
                
                if ( node.left != null ) {
                    queue.add( node.left );
                }
            
                if ( node.right != null ) {
                    queue.add( node.right );
                }

                sum += node.val;
            }

            if ( sum > max_sum ) {
                max_sum = sum;
                max_level = level;
            }

            level++;
        }
        return max_level;
    }
}