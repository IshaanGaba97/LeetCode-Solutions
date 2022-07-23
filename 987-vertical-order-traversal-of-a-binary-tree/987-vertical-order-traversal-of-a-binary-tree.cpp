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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<int>> m;  //verlevel - elements
        queue<pair<int, TreeNode*>> q;
        q.push(make_pair(0, root));
            
        while(!q.empty()){
        vector<pair<int, int>> tmp;
            
        int len=q.size();
        for(int i=0;i<len;++i){
            auto p=q.front();q.pop();
            tmp.push_back(make_pair(p.first, p.second->val));
            // tmp[p.first].push_back(p.second->val);
            if(p.second->left) q.push(make_pair(p.first-1, p.second->left));
            if(p.second->right) q.push(make_pair(p.first+1, p.second->right));
        }
            sort(tmp.begin(), tmp.end());
            for(auto p : tmp) m[p.first].push_back(p.second);   //level - val
        }
        
        vector<vector<int>> res;
        for(auto i : m){
            res.push_back(i.second);
        }
        return res;
    }
};