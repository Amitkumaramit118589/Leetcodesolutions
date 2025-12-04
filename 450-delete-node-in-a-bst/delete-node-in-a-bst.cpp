class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* curr = root;
        TreeNode* parent = nullptr;

        // 1) Find the node to delete and its parent
        while (curr != nullptr && curr->val != key) {
            parent = curr;
            if (key < curr->val) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }

        // Key not found
        if (curr == nullptr) return root;

        // Helper lambda to replace a child of parent with newChild
        auto replaceChild = [&](TreeNode* parent, TreeNode* oldChild, TreeNode* newChild) {
            if (parent == nullptr) {
                // oldChild was root
                root = newChild;
            } else if (parent->left == oldChild) {
                parent->left = newChild;
            } else if (parent->right == oldChild) {
                parent->right = newChild;
            }
        };

        // 2) Case: node has at most one child
        if (curr->left == nullptr || curr->right == nullptr) {
            TreeNode* child = (curr->left != nullptr) ? curr->left : curr->right;

            replaceChild(parent, curr, child);
            delete curr;
        } 
        // 3) Case: node has two children
        else {
            // Find inorder successor: smallest in right subtree
            TreeNode* succParent = curr;
            TreeNode* succ = curr->right;
            while (succ->left != nullptr) {
                succParent = succ;
                succ = succ->left;
            }

            // Copy successor's value into current node
            curr->val = succ->val;

            // Now delete the successor node (succ has at most one right child)
            TreeNode* succChild = succ->right;  // left is nullptr
            if (succParent->left == succ) {
                succParent->left = succChild;
            } else {
                succParent->right = succChild;
            }
            delete succ;
        }

        return root;
    }
};
