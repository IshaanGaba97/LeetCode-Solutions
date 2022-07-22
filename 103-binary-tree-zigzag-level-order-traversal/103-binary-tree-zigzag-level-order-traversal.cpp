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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL)
            return res;
        
        int count = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> ans;
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();
                
                ans.push_back(node->val);
                
                if(node->left != NULL)
                    q.push(node->left);
                if(node->right != NULL)
                    q.push(node->right);

            }
            if(count%2 == 0){
                     res.push_back(ans);
            }
            else{
                reverse(ans.begin(), ans.end());
                res.push_back(ans);
            }
            count++;
        }
        return res;
    }
};