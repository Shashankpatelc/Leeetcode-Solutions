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
    int height_fun(TreeNode* node){
        int h = 0;
        while(node->left != nullptr){
            node = node->left;
            h++;
        }
        return h;
    }

    bool nodeexist(TreeNode* node, int height, int pos){
        int mask = 1 << (height - 1);
        
        for(int i = 0; i < height; i++){
            if(pos & mask){
                node = node->right;
            } else {
                node = node->left;
            }
            mask = mask >> 1;
        }
        
        return node != nullptr;
    }

    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        
        int h = height_fun(root);

        if (h == 0) return 1; 
        
        int completeNodes = (1 << h) - 1;
        
        int left = 0;
        int right = (1 << h) - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nodeexist(root, h, mid)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        int lastLevelNodes = right + 1;
        
        return completeNodes + lastLevelNodes;
    }
};

