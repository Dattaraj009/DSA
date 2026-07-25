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
    int cnt = 0;
    void solve(TreeNode* root,int maxi){
       if(!root) return;
       if(maxi <= root->val){
        cnt++;
        maxi = root->val;
       }
       solve(root->left,maxi);
       solve(root->right,maxi);
    //    if(root->val <= left){
    //      cnt++;
    //    } 
    //    else{
    //     cnt = 0;
    //    }
    //    if(root->val <= right){
    //        cnt++;
    //    }else{
    //     cnt = 0;
    //    } 

    //    return max({root->val,left,right});
    }
    int goodNodes(TreeNode* root) {
        solve(root,INT_MIN);
        return cnt;
    }
};