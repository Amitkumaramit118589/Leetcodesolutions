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
//class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//           if(root==NULL) return {};
//         stack<TreeNode*>stk;
//         vector<int>result;
        
//        while(root || !stk.empty()){
//          while(root){
//             stk.push(root);
//             root =  root->left;
//          }
//          root  = stk.top();
//          stk.pop();
//          result.push_back(root->val);
//          root  = root->right;
//        }
//         return result;
//     }
// };

// MORIS TRAVERSAL

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
         if(root==NULL) return {};
         vector<int>res;

         TreeNode* curr = root;

         while(curr!=NULL){

            if(curr->left==NULL){
                res.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode* currleft= curr->left;

                while(currleft->right != NULL){
                    currleft= currleft->right;
                }
                currleft->right = curr;

                TreeNode* temp = curr;
                curr = curr->left;
                temp->left = NULL;
            }
         }
        return res;
    }
};