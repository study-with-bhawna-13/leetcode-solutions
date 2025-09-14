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
    int sumNumbers(TreeNode* root, int curr = 0) {
        if(!root) return 0;
        if(!root->left && !root->right) return curr*10+root->val;
        return sumNumbers(root->left, curr*10+root->val)+sumNumbers(root->right, curr*10+root->val);
    }
};