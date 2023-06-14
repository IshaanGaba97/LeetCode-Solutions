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
    int mini = INT_MAX;
    int prev = INT_MAX;
    void inorder(TreeNode* root){
        if(!root) return;

        inorder(root->left);

        if(abs(root->val - prev) < mini) 
        mini = abs(root->val-prev);

        prev = root->val;
        inorder(root->right); 
    }
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return mini;
    }
};