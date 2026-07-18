/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void store(TreeNode* root,vector<int> adj[]){
        if(!root) return;
        if(root->left)adj[root->val].push_back(root->left->val);
        if(root->left)adj[root->left->val].push_back(root->val);
        if(root->right)adj[root->right->val].push_back(root->val);
        if(root->right)adj[root->val].push_back(root->right->val);

        store(root->left,adj);
        store(root->right,adj);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> adj[501];
        vector<int> vis(501,0);
        vector<int> ans;
        store(root,adj);
        queue<pair<int,int>> q;// val, steps
        q.push({target->val,0});
        vis[target->val] = 1;
        while(!q.empty()){
            auto[node,steps] = q.front();
            q.pop();
            if(steps==k){
                ans.push_back(node);
                continue;
            }

            for(auto it:adj[node]){
                if(!vis[it]){
                    q.push({it,steps+1});
                    vis[it] = 1;
                }
            }
        }

        return ans;
    }
};