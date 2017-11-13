/*
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal
 *
 * algorithms
 * Medium (32.54%)
 * Total Accepted:    95.3K
 * Total Submissions: 292.7K
 * Testcase Example:  '[]\n[]'
 *
 * Given inorder and postorder traversal of a tree, construct the binary tree.
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, 0, inorder.size(),
                         postorder, 0, postorder.size());
    }

private:
    TreeNode* buildTree(vector<int>& inorder, int i, int j,
                        vector<int>& postorder, int ii, int jj) {
        if (i >= j || ii >= jj) return NULL;

        int mid = postorder[jj-1];
        vector<int>::iterator index = find(inorder.begin()+i,inorder.begin()+j, mid);
        int leftSize = index - inorder.begin() - i;

        TreeNode* root = new TreeNode(mid);
        root->left = buildTree(inorder, i, i+leftSize,
                               postorder, ii, ii+leftSize);
        root->right = buildTree(inorder, i+leftSize+1, j,
                                postorder, ii+leftSize, jj-1);
        return root;
    }
};
