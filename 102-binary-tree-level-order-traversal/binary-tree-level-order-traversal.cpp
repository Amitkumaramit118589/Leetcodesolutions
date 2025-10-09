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
    int levels(TreeNode* root){
        if(root==NULL)return 0;
        return 1+max(levels(root->left),levels(root->right));
    }
    void lorder(TreeNode* root,int level,int curr,vector<int>&lans){
        if(root==NULL)return;
        if(level==curr){
            lans.push_back(root->val);
            return;
        }
        lorder(root->left,level,curr+1,lans);
        lorder(root->right,level,curr+1,lans);

    }
    void help(TreeNode* root,vector<vector<int>>&ans){
        int n=levels(root);
        for(int i=0;i<n;i++){
            vector<int>temp;
            lorder(root,i,0,temp);
            ans.push_back(temp);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        help(root,ans);
        return ans;
    }
};