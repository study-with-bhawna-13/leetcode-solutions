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
    static void traverse(map<int,map<int,vector<int>>> &m, TreeNode *root, int i=0,int j=0){
        if(root == nullptr) return;
        if(m[i].find(j)!=m[i].end())
        m[i][j].push_back(root->val);
        else
        m[i][j] = {root->val};
        traverse(m,root->left,i-1,j+1);
        traverse(m,root->right,i+1,j+1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,vector<int>>> m;
        vector<vector<int>> ans;
        traverse(m,root);
        for(auto i: m){
            vector<int> tmp;
            for(auto j: i.second){
                sort(j.second.begin(),j.second.end());
                for(auto k: j.second){
                tmp.push_back(k);
                }
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};