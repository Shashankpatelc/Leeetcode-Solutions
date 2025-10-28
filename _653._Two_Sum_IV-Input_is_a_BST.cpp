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
    bool findTarget(TreeNode* root, int k) {
        int temp;
        unordered_set<int> s;
        queue<TreeNode*> q;
        TreeNode* node;

        q.push(root);
        while(!q.empty()){
        
            node = q.front();
            temp = k - node->val;
            if (s.find(temp) != s.end()){
                return true;
            } else {
                s.insert(node->val);
            }
            q.pop();

            if (node->left != nullptr){
                q.push(node->left);
            }
            
            if (node->right != nullptr){
                q.push(node->right);
            }
        }
        return false;
    }
};

