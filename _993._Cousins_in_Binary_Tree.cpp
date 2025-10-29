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
    bool isCousins(TreeNode* root, int x, int y) {
        int len = 0;
        bool xval = false, yval = false; 
        queue<TreeNode*> q;
        TreeNode* node;
        TreeNode* parentx = nullptr;
        TreeNode* parenty = nullptr;

        q.push(root);
        while(!q.empty()){
            xval = false;
            yval = false;
            len = q.size();

            for (int i = 0; i < len; i++ ){
            
                node = q.front();
                q.pop();
            
                if (node->left){
                    if (node->left->val == x){
                        xval = true;
                        parentx = node;
                    }
                    if (node->left->val == y){
                        yval = true;
                        parenty = node;
                    }
                    q.push(node->left);
                }
                
                if (node->right){
                    if (node->right->val == x){
                        xval = true;
                        parentx = node;
                    }
                    if (node->right->val == y){
                        yval = true;
                        parenty = node;
                    }   
                    q.push(node->right);
                }

                if (xval && yval){
                    return parentx != parenty;
                }
            }
        }
        return false;
    }
};

