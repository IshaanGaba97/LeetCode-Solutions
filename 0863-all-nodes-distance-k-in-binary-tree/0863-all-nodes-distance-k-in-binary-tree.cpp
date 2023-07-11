class Solution {
public:

    void getValue(TreeNode*root,unordered_map<TreeNode*,bool> &visited,unordered_map<TreeNode*,TreeNode*> parentNode,int k,vector<int> &ans){
        if(root==NULL || visited[root] || k<0){
            return;
        }
        visited[root]=true;
        if(k==0){
            ans.push_back(root->val);
        }
        getValue(root->left,visited,parentNode,k-1,ans);
        getValue(root->right,visited,parentNode,k-1,ans);
        getValue(parentNode[root],visited,parentNode,k-1,ans);
    }

    void getParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parentNode){
        if(root==NULL){
            return;
        }
        if(root->left){
            parentNode[root->left]=root;
        }
        if(root->right){
            parentNode[root->right]=root;
        }
        getParent(root->left,parentNode);
        getParent(root->right,parentNode);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parentNode;
        getParent(root,parentNode);

        unordered_map<TreeNode*,bool> visited;
        vector<int> ans;
        getValue(target,visited,parentNode,k,ans);
        return ans;
    }
};