# include<bits/stdc++.h>
/**
 * Definition for a binary tree node.
 */

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

using namespace std;

class Solution {
public:
    int minDepth(TreeNode* node){
        int left = 0, right = 0;
        if(node == nullptr){
            return 0;
        }

        if(node->left == nullptr && node->right == nullptr){
            return 1;
        }

        if(node->left != nullptr){
            left = minDepth(node->left);
        } else {
            left = std::numeric_limits<int>::max();
        }

        if(node->right != nullptr){
            right = minDepth(node->right);
        } else {
            right = std::numeric_limits<int>::max();
        }

        return min(left,right) + 1;
    }
};
