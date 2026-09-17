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
    void solve(TreeNode* root,vector<int> adj[]){
        if(!root) return;
        if(root->left){
            adj[root->left->val].push_back(root->val);
            adj[root->val].push_back(root->left->val);
        }
        if(root->right){
            adj[root->right->val].push_back(root->val);
            adj[root->val].push_back(root->right->val);
        }
        solve(root->left,adj);
        solve(root->right,adj);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> adj[501];
         solve(root,adj);
        queue<pair<int,int>> q;
        q.push({target->val,0});
        vector<int> vis(501,0);
        vis[target->val] = 1;
        vector<int> ans;
        while(!q.empty()){
             auto [val,steps] = q.front();
             q.pop();
             if(steps==k){
                ans.push_back(val);
             }
             for(auto adjval:adj[val]){
                if(!vis[adjval]){
                   q.push({adjval,steps+1});
                   vis[adjval] = 1;
                }
             }
        }

        return ans;
    }
};