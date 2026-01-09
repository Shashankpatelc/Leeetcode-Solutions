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
 
class node_depth {
    TreeNode node;
    int dist;
    node_depth(TreeNode node, int dist) {
        this.node = node;
        this.dist = dist;
    }
}

class Solution {

    public node_depth depth(TreeNode root) {
        if (root == null) {
            return new node_depth(null, -1);
        }

        node_depth left_d = depth(root.left);
        node_depth right_d = depth(root.right);
        
        if (left_d.dist == right_d.dist) {
            return new node_depth(root, left_d.dist + 1);
        }
        
        if (left_d.dist > right_d.dist) {
            return new node_depth(left_d.node, left_d.dist + 1);
        }
        
        return new node_depth(right_d.node, right_d.dist + 1);
    }

    public TreeNode subtreeWithAllDeepest(TreeNode root) {
        return depth(root).node;
    }
}