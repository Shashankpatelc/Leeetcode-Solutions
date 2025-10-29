/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// DFS
class Solution {
public:
    TreeNode* dfs(TreeNode* original, TreeNode* cloned, TreeNode* target){
        if (!original) return nullptr;
        if (original == target) return cloned;

        TreeNode* left = dfs(original->left,cloned->left,target);
        if (left) return left;
        TreeNode* right = dfs(original->right,cloned->right,target);
        return right;
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return dfs(original,cloned,target);
    }
};

// BFS
class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* node1 = nullptr;
        TreeNode* node2 = nullptr;

        queue<TreeNode*> q1;
        queue<TreeNode*> q2;

        q1.push(original);
        q2.push(cloned);

        while(!q1.empty()){
            node1 = q1.front();
            node2 = q2.front();

            q1.pop();
            q2.pop();

            if (node1 == target) return node2;

            if (node1->left) q1.push(node1->left);
            if (node1->right) q1.push(node1->right);

            if (node2->left) q2.push(node2->left);
            if (node2->right) q2.push(node2->right);
        }
        return node2;
    }
};

