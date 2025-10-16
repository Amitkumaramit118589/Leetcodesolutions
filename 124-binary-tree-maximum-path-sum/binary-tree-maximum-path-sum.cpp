class Solution {
public:
    int maxsum = INT_MIN;

    int solve(TreeNode* root) {
        if (root == NULL) return 0;

        int l = max(0, solve(root->left));
        int r = max(0, solve(root->right));

        int a = l + r + root->val; // path passes through this node
        int b = max(l, r) + root->val; // path from this node to parent
        int c = root->val; // only the node itself

        maxsum = max({maxsum, a, b, c});
        return max(b, c); // return max gain to parent
    }

    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxsum;
    }
};
