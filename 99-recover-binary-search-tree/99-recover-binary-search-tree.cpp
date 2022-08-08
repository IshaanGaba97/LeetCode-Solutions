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
private: 
    TreeNode* first;
    TreeNode* last;
    TreeNode* middle;
    TreeNode* prev;
public:
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        if(prev != NULL && (root->val < prev->val)){
            //first voilation -> adjacent swapped case - ret first/middle
            if(first == NULL){ 
                first = prev;
                middle = root;
            }
            //second voilation -> non adjacent swapped case - ret first/last
            else 
                last = root;
        }
        prev = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if(first && last) swap(first->val, last->val);
        else if(first && middle) swap(first->val, middle->val);
    }
};