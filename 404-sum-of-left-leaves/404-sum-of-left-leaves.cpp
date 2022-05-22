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
    int total = 0;
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL) return 0;
        helper(root, false);
        return total;
    }
    void helper(TreeNode* root, bool isLeft){
        if(root == NULL) return;
    if(isLeft && root->left == NULL && root->right == NULL){
        total += root->val;
        return;
    }
    helper(root->left, true);
    helper(root->right, false);
    }
};