/*
 * [95] Unique Binary Search Trees II
 *
 * https://leetcode.com/problems/unique-binary-search-trees-ii
 *
 * algorithms
 * Medium (31.33%)
 * Total Accepted:    89.4K
 * Total Submissions: 282.6K
 * Testcase Example:  '3'
 *
 * Given an integer n, generate all structurally unique BST's (binary search
 * trees) that store values 1...n.
 * 
 * 
 * For example,
 * Given n = 3, your program should return all 5 unique BST's shown below.
 * 
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return vector<TreeNode*>();
        return generateTrees(1, n);
    }
private:
    vector<TreeNode*> generateTrees(int start, int end) {
        vector<TreeNode*> res;

        if (start > end) {
            res.push_back(nullptr);
            return res;
        }

        if (start == end) {
            res.push_back(new TreeNode(start));
            return res;
        }

        vector<TreeNode*> left, right;
        for (int i = start; i <= end; ++i) {
            left = generateTrees(start, i-1);
            right = generateTrees(i+1, end);

            for (auto lnode : left) {
                for (auto rnode : right) {
                    TreeNode* root = new TreeNode(i);
                    root->left = lnode;
                    root->right = rnode;
                    res.push_back(root);
                }
            }
        }

        return res;
    }
};
