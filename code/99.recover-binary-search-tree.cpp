/*
 * [99] Recover Binary Search Tree
 *
 * https://leetcode.com/problems/recover-binary-search-tree
 *
 * algorithms
 * Hard (29.85%)
 * Total Accepted:    79.1K
 * Total Submissions: 262.1K
 * Testcase Example:  '[0,1]'
 *
 * 
 * Two elements of a binary search tree (BST) are swapped by mistake.
 * 
 * Recover the tree without changing its structure.
 * 
 * 
 * Note:
 * A solution using O(n) space is pretty straight forward. Could you devise a
 * constant space solution?
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
    void recoverTree(TreeNode* root) {
        traverse(root);

        swap(nodeA->val, nodeB->val);
    }

private:
    void traverse(TreeNode* root) {
        if (root == NULL) return ;

        traverse(root->left);

        if (nodeA == NULL && preNode->val >= root->val)
            nodeA = preNode;
        if (nodeA != NULL && preNode->val >= root->val)
            nodeB = root;
        preNode = root;

        traverse(root->right);
    }

private:
    TreeNode* nodeA = NULL;
    TreeNode* nodeB = NULL;
    TreeNode* preNode = new TreeNode(INT_MIN);
};
