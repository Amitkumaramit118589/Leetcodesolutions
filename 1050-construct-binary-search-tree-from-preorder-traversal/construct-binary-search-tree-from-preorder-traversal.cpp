
class Solution {
public:
   void insert(TreeNode* root, int val) {
        TreeNode* curr=root;
        TreeNode* t=new TreeNode(val);
        
        while(true){
            if(curr->val<=val) 
               if(curr->right!=NULL)curr=curr->right;
               else {
                  curr->right=t;
                  break;
               }
            else{
                if(curr->left!=NULL)curr=curr->left;
                else{
                    curr->left=t;
                    break;
                }
            }
        }
        
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root= new TreeNode(preorder[0]);
        for(int i=1;i<preorder.size();i++){
            insert(root,preorder[i]);
        }
       return root;
    }
};