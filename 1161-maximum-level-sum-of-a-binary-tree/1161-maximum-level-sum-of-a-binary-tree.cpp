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
    int maxLevelSum(TreeNode* root) {
        map<int, int> mp;
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        while(q.size() > 0){
            int size = q.size();
            int sum = 0;
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front(); q.pop();
                sum += node->val;
                if(node->left != NULL){
                    q.push(node->left);
                }
                if(node->right != NULL){
                    q.push(node->right);
                }
            }
            mp[level] = sum;
            level++;
        }
        
        int maxi = INT_MIN;
        int ans = 0;
        for(auto it : mp){
            if(it.second > maxi){
                maxi = it.second;
                ans = it.first;
            }
        }
        return ans;
    }
};