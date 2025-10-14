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
    int getheight(TreeNode* root){
        if(root==NULL)return 0;
        int leftsubtreeheight=getheight(root->left);
        int rightsubtreeheight=getheight(root->right);
        if(leftsubtreeheight==-1 || rightsubtreeheight==-1 || abs(leftsubtreeheight-rightsubtreeheight)>1) return -1;
        return 1+max(leftsubtreeheight,rightsubtreeheight);
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        if(getheight(root)==-1) return false;
        else return true;
    }
};