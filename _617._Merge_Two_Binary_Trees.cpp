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
    TreeNode* merge(TreeNode* node1, TreeNode* node2, TreeNode* newtree){
        if (node1 == nullptr && node2 == nullptr){
            return node1;
        }
        else if (node1 == nullptr){
            return node2;

        } else if (node2 == nullptr){
            return node1;

        }
        else{
            TreeNode* node(new TreeNode(node1->val + node2->val));
            newtree = node;
        }

        TreeNode* left = merge(node1->left,node2->left,newtree->left);
        TreeNode* right = merge(node1->right,node2->right,newtree->right);

        newtree->left = left;
        newtree->right = right;
        return newtree;
    }

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode* newtree;
        return merge(root1,root2,newtree);
    }
};

