class Solution {
public:
    
    long long prev = LLONG_MIN;

    bool inorder(TreeNode* root) {

        if (root == NULL)
            return true;

        // visit left subtree
        if (!inorder(root->left))
            return false;

        // check current node
        if (root->val <= prev)
            return false;

        prev = root->val;

        // visit right subtree
        return inorder(root->right);
    }

    bool isValidBST(TreeNode* root) {
        return inorder(root);
    }
};
