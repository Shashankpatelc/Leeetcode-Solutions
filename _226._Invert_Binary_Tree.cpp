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
 

#include<deque>

using namespace std;

class Solution {
public:
    TreeNode* invertTree(TreeNode* node){

        if(node == nullptr){
            return nullptr;
        }

        TreeNode* left = node->left;
        TreeNode* right = node->right;

        node->left = invertTree(right);
        node->right = invertTree(left);

        return node;
    }
};

