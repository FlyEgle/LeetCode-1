/*
 * [103] Binary Tree Zigzag Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal
 *
 * algorithms
 * Medium (35.46%)
 * Total Accepted:    116.9K
 * Total Submissions: 329.7K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the zigzag level order traversal of its nodes'
 * values. (ie, from left to right, then right to left for the next level and
 * alternate between).
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
 * return its zigzag level order traversal as:
 * 
 * [
 * ⁠ [3],
 * ⁠ [20,9],
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) return res;

        deque<TreeNode*> deq;
        deq.push_back(root);
        bool iszigzag = false;
        while (!deq.empty()) {
            int size = deq.size();
            vector<int> level;
            for (int i = 0; i < size; ++i) {
                if (iszigzag) {
                    TreeNode* node = deq.back();
                    deq.pop_back();
                    level.push_back(node->val);
                    if (node->right) deq.push_front(node->right);
                    if (node->left) deq.push_front(node->left);
                } else {
                    TreeNode* node = deq.front();
                    deq.pop_front();
                    level.push_back(node->val);
                    if (node->left) deq.push_back(node->left);
                    if (node->right) deq.push_back(node->right);
                }
            }
            res.push_back(level);
            iszigzag = !iszigzag;
        }

        return res;
    }
};
