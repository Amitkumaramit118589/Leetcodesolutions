/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Helper function to check if two trees are mirror images
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // If either is NULL, both must be NULL for symmetry
        if(p == NULL || q == NULL) {
            return (p == q);
        }
        
        // Check: current values match AND left mirrors right AND right mirrors left
        return (p->val == q->val) && 
               isSameTree(p->left, q->right) && 
               isSameTree(p->right, q->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        // Compare left and right subtrees
        return isSameTree(root->left, root->right);
    }
};