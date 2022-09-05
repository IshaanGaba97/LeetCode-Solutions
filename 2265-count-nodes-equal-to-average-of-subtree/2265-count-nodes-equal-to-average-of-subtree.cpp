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
    // pair - sum , number of nodes
    pair<int,int> rec(TreeNode* root){
        if(!root) return {0,0};
        pair<int,int> lh= rec(root->left);
        pair<int,int> rh = rec(root->right);
        int sum = lh.first + rh.first + root->val;
        int count = lh.second + rh.second + 1;
        return {sum, count};
    }
    void preorder(TreeNode* root, int& cnt){
        if(!root) return;
        pair<int,int> p = rec(root);
        if(root->val == (p.first/p.second))
            cnt++;
        preorder(root->left,cnt);
        preorder(root->right,cnt);
    }
    
    int averageOfSubtree(TreeNode* root) {
        if(!root) return 0;
        int cnt = 0;
        preorder(root, cnt);
        return cnt;
    }
};