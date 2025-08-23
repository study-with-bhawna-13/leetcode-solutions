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
    int fun(TreeNode *root, int low, int high, int &ans){
        if(root == nullptr) return ans;
        if(root->val<=high && root->val>=low) ans+=root->val;
        fun(root->left,low,high,ans);
        fun(root->right,low,high,ans); 
        return ans;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans=0;
        return fun(root,low,high,ans);
    }
};