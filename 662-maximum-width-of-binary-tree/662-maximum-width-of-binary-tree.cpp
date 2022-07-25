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
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 0;
        if(root == NULL) return 0;
        queue<pair<TreeNode*, int>> q;    //node - index
        q.push({root, 0});
        while(!q.empty()){
            int size = q.size();
            int mmin = q.front().second;
            int first, last;
            for(int i = 0; i < size; i++){
                int currid = q.front().second - mmin;
                TreeNode* node = q.front().first;
                q.pop();
                
                if(i==0) first = currid;
                if(i==size-1) last = currid;
                
                if(node->left) 
                    q.push({node->left, (long long)currid*2+1});
                if(node->right) 
                    q.push({node->right, (long long)currid*2+2});
            }
            int width = last - first + 1;
            ans = max(ans, width);
        }
        return ans;
    }
};