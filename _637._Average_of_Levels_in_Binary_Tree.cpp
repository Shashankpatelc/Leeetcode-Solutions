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
    vector<double> averageOfLevels(TreeNode* root) {

        int len = 0;
        double sum = 0;
        TreeNode* node;
        vector<double> v;
        deque<TreeNode*> q;

        q.push_back(root);

        while(!q.empty()){
            len = q.size();

            for(int i = 0; i < len; i++){

                node = q.front();
                q.pop_front();
                sum += node->val;

                if(node->left != nullptr){
                    q.push_back(node->left);
                }
                if (node->right != nullptr){
                    q.push_back(node->right);
                }
            }

            v.push_back(sum/len);
            sum = 0;
        }
        return v;
    }
};

