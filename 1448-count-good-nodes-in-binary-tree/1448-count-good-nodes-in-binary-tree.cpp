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
    int goodNodes(TreeNode* root) {
        int maxsofar = INT_MIN;
        return dfs(root, maxsofar);
    }
    int dfs(TreeNode* root, int maxsofar){
        if(!root) return 0;
        
        if(root->val >= maxsofar){
            return dfs(root->left, root->val) + dfs(root->right, root->val) + 1;
        }
        return dfs(root->left, maxsofar) + dfs(root->right, maxsofar);
    }
};