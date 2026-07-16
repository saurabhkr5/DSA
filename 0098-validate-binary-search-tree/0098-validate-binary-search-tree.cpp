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