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
    int level(TreeNode* root){
        if(root==NULL)return 0;
        return 1+max(level(root->left),level(root->right));
    }
    int maxdia=0;
    int diameterOfBinaryTree(TreeNode* root) {
         if(root==NULL)return 0;
         int height=level(root->left)+level(root->right);
         maxdia=max(maxdia,height);
         diameterOfBinaryTree(root->left);
         diameterOfBinaryTree(root->right);
         return maxdia;
    }
};