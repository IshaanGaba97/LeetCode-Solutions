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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return false;
        return symmetrichelper(root->left, root->right);
    }
    bool symmetrichelper(TreeNode* left, TreeNode* right){
        if(left == NULL || right == NULL)
            return left == right;
        
        if(left->val != right->val)
            return false;
        
        return symmetrichelper(left->left, right->right) && symmetrichelper(left->right, right->left);
    }
    
};