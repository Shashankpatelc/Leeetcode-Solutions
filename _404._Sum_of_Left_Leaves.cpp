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
    int allsum(TreeNode* node,int dis){
        
        int left = 0,right = 0; 
        
        if(node == nullptr){
            return 0;
        }

        if (node->left == nullptr && node->right == nullptr && dis){
            return node->val;
        }

        left += allsum(node->left,1);
        right = allsum(node->right,0);

        return left + right;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        return allsum(root,0);
    }
};

