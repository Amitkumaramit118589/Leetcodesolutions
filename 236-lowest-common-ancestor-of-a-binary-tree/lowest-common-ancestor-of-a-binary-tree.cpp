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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: if root is NULL or matches p or q, return root
        if(root == NULL || root == p || root == q) return root;

        // Search for p and q in left and right subtrees
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // If left is NULL, both p and q are in right subtree
        if(left == NULL) return right;
        // If right is NULL, both p and q are in left subtree
        else if(right == NULL) return left;
        // If both non-null, p and q are in different subtrees, root is LCA
        else return root;
    }
};