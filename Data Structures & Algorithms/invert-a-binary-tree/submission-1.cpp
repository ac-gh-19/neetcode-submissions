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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return nullptr;
        if (root->left == nullptr and root->right == nullptr) return root;

        TreeNode* leftNode = nullptr;
        if (root->left) {
            leftNode = invertTree(root->left);
        }

        TreeNode* rightNode = nullptr;
        if (root->right) {
            rightNode = invertTree(root->right);
        }

        TreeNode* temp;
        if (leftNode) {
            temp = leftNode;
            root->left = root->right;
            root->right = leftNode;
        } else if (rightNode) {
            temp = rightNode;
            root->right = root->left;
            root->left = rightNode;
        }
        

        return root;
    }
};
