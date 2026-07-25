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
    void solve(TreeNode* root,vector<string>& store,string ans){
        if(!root) return;
        ans += to_string(root->val);
        ans += "->";
        if(!root->left && !root->right){
            ans.pop_back();
            ans.pop_back();
            store.push_back(ans);
        }
        else{
            solve(root->left,store,ans);
            solve(root->right,store,ans);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> store;
        string ans = "";
        solve(root,store,ans);
        return store;
    }
};