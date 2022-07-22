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
    int depth(TreeNode* root){
        if(root == NULL)return 0;
        return max(depth(root->right),depth(root->left))+1;
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
     if(root == NULL)return {};
        int d = depth(root);
		//initialise the empty levels inside a vector
        vector<vector<int> > level(d,vector<int>({})); 
        int i = 0;
        queue<TreeNode*> q;
        q.push(root);
        level[d-1].push_back(root->val);
        q.push(NULL);
        d--;

        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            
            if(temp){  
                if(temp->left){
                        q.push(temp->left);
                        level[d-1].push_back(temp->left->val);
                    }    
                if(temp->right){
                        q.push(temp->right);
                        level[d-1].push_back(temp->right->val);
                    }
            }                 
            else {
                if(q.empty()) break;
                d--;
                q.push(NULL);
            }  
        }
        return level;
    }
};