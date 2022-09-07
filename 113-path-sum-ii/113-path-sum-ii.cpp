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
    void preorder(TreeNode* root, vector<int>& ds, vector<vector<int>>& res, int target){          
        if(!root) return;
        
        target = target - root->val;
        ds.push_back(root->val);
        
        if(!root->left && !root->right && target == 0) {
            res.push_back(ds);
        }
        preorder(root->left, ds, res, target);
        preorder(root->right, ds, res, target);
        
        ds.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        if(!root) return res;
        vector<int> ds;
        preorder(root, ds, res, targetSum);
        return res;
    }
};