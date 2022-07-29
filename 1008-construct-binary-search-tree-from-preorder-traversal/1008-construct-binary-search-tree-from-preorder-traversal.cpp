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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return bstFromPreorder(preorder, i, INT_MAX);
    }
    TreeNode* bstFromPreorder(vector<int>& preorder, int& i, int maxValueBound){
        if(i == preorder.size() || preorder[i] > maxValueBound) return NULL;
        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = bstFromPreorder(preorder, i, root->val);
        root->right = bstFromPreorder(preorder, i, maxValueBound);
        return root;
    }
};