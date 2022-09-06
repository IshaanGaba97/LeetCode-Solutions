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
    int subtree(TreeNode* root){
        if(!root) return 0;
        int sum = 0;
        sum += root->val;
        sum += subtree(root->left);
        sum += subtree(root->right);
        return sum;
    }
    void preorder(TreeNode* root, unordered_map<int,int>& mp, int& maxfreq){
        if(!root) return;
        int subtreeSum = subtree(root);
        mp[subtreeSum]++;
        if(mp[subtreeSum] > maxfreq) 
            maxfreq = mp[subtreeSum];
        preorder(root->left, mp, maxfreq);
        preorder(root->right, mp, maxfreq);
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if(!root) return{};
        vector<int> ans;
        unordered_map<int,int> mp;
        int maxfreq = 0;
        preorder(root, mp, maxfreq);
        
        for(auto it : mp){
            if(it.second == maxfreq)
                ans.push_back(it.first);
        }
        return ans;
    }
};