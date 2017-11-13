/*
 * [104] Maximum Depth of Binary Tree
 *
 * https://leetcode.com/problems/maximum-depth-of-binary-tree
 *
 * algorithms
 * Easy (53.31%)
 * Total Accepted:    280.6K
 * Total Submissions: 526.1K
 * Testcase Example:  '[]'
 *
 * Given a binary tree, find its maximum depth.
 * 
 * The maximum depth is the number of nodes along the longest path from the
 * root node down to the farthest leaf node.
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int res = 0;
        if (root == NULL) return res;

        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            res++;

            int size = que.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* node = que.front();
                que.pop();
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }

        return res;
    }
};
