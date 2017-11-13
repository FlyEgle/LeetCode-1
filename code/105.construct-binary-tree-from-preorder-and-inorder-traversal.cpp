/*
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal
 *
 * algorithms
 * Medium (32.73%)
 * Total Accepted:    117.8K
 * Total Submissions: 360K
 * Testcase Example:  '[]\n[]'
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, 0, preorder.size(),
                         inorder, 0, inorder.size());
    }

private:
    TreeNode* buildTree(vector<int>& preorder, int i, int j, vector<int>& inorder, int ii, int jj) {
        if (i >= j || ii >= jj) return NULL;

        int mid = preorder[i];
        vector<int>::iterator index = find(inorder.begin()+ii, inorder.begin()+jj, mid);
        int leftSize = index - inorder.begin() - ii;

        TreeNode* root = new TreeNode(mid);
        root->left = buildTree(preorder, i+1, i+1+leftSize,
                               inorder, ii, ii+leftSize);
        root->right = buildTree(preorder, i+1+leftSize, j,
                                inorder, ii+leftSize+1, jj);
        return root;
    }
};
