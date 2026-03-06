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
public:
    TreeNode* div_con(vector<int>& arr, int start, int end) {
        if(start > end) return nullptr;
        
        int mid = start + (end - start) / 2;
        
        TreeNode* node = new TreeNode(arr[mid]);

        node->left = div_con(arr, start, mid - 1);
        node->right = div_con(arr, mid + 1, end);

        return node;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return div_con(nums, 0, size(nums)-1);
    }
};