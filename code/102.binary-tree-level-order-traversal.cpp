/*
 * [102] Binary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal
 *
 * algorithms
 * Medium (40.88%)
 * Total Accepted:    200.3K
 * Total Submissions: 489.9K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the level order traversal of its nodes' values.
 * (ie, from left to right, level by level).
 * 
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 
 * return its level order traversal as:
 * 
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
 * ]
 * 
 * 
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> qu;
        qu.push(root);
        int times = 1;

        while (!qu.empty()) {
            vector<int> level;
            int next = 0;
            for (int i = 0; i < times; ++i) {
                if (qu.empty()) break;
                TreeNode* tmp = qu.front();
                qu.pop();
                if (tmp == NULL) continue;

                level.push_back(tmp->val);
                qu.push(tmp->left);
                qu.push(tmp->right);
                next += 2;
            }

            if (!level.empty())
                res.push_back(level);
            times = next;
        }

        return res;
    }
};
