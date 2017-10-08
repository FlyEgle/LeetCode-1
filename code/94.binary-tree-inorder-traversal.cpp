/*
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal
 *
 * algorithms
 * Medium (46.35%)
 * Total Accepted:    224.4K
 * Total Submissions: 474.7K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the inorder traversal of its nodes' values.
 * 
 * 
 * For example:
 * Given binary tree [1,null,2,3],
 * 
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * 
 * 
 * return [1,3,2].
 * 
 * 
 * Note: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == NULL) return vector<int>();

        vector<int> res;
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node->left) {
                st.push(node->left);
                node->left = NULL;
            } else {
                res.push_back(node->val);
                st.pop();
                if (node->right) st.push(node->right);
            }
        }

        return res;
    }
};
