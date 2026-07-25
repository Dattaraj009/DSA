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
        if(!root){
        //    store.push_back(ans);
           return;
        } 
        ans += to_string(root->val);
        if(!root->left && !root->right){
           store.push_back(ans);
        }
        else{
             solve(root->left,store,ans);
             solve(root->right,store,ans);
        }
        
    }
    int sumNumbers(TreeNode* root) {
        vector<string> store;
        int val = 0;
        string ans = "";
        solve(root,store,ans);
        // for(auto a:store){
        //     cout<<a<<endl;
        // }
        for(int i=0;i<store.size();i++){
            if(store[i]!=""){
               val += stoi(store[i]);
            }
        }

        return val;
    }
};