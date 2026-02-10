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
class Solution {

private:
    void in_order(vector<int> &vals, TreeNode* node) {
    
        if( node == nullptr ) {
            return;
        }

        in_order(vals, node->left);
        vals.push_back(node->val);
        in_order(vals, node->right);

    }

    TreeNode* build(vector<int> &vals, int start, int end) {
        if( start > end ) return nullptr;

        int mid = (start + end) / 2;
        TreeNode* node = new TreeNode(vals[mid]);

        node->left = build(vals, start, mid - 1);
        node->right = build(vals, mid + 1, end);
        return node;
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> vals;
        in_order(vals, root);
        return build(vals, 0, vals.size() - 1);
    }
};