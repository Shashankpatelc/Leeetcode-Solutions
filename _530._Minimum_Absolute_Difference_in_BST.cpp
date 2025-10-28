#include<bits/stdc++.h>

using namespace std;

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
 
class Solution {
public:
    
    int mindiff = INT_MAX;
    int prev = -1;

    void in_order(TreeNode* node){
    
        if(node == nullptr){
            return;
        }
    
        in_order(node->left);
        if (prev != -1){
            mindiff = min(mindiff,node->val - prev);
        }
        prev = node->val;
        in_order(node->right);
    }

    int getMinimumDifference(TreeNode* root) {

        in_order(root);
        return mindiff;
    }
};

