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
    void dfs(TreeNode* root, vector<int> &l){
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) l.push_back(root->val);
        dfs(root->left, l);
        dfs(root->right, l);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> l1;
        vector<int> l2;
        dfs(root1, l1);
        dfs(root2, l2);
        return (l1==l2);
    }
};