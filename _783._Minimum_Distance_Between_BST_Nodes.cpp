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
    int minDiffInBST(TreeNode* root) {
        int min_val = INT_MAX;
        vector<int> v;
        queue<TreeNode*> q;
        TreeNode* node;

        q.push(root);

        while(!q.empty()){
            node = q.front();
            v.push_back(node->val);
            q.pop();

            if (node->left != nullptr){
                q.push(node->left);
            }
                
            if (node->right != nullptr){
                q.push(node->right);
            }
        }
        sort(v.begin(),v.end());
        for(auto i = 0,j = 1;i < v.size()-1;i++,j++){
            min_val = min(min_val,v[j]-v[i]);
        }
        return min_val;
    }
};

