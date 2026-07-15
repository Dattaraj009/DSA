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
    int solve(TreeNode* root,int val){
         if(!root) return 0;
         if(val==0 && !root->left && !root->right) return root->val;

         int left = solve(root->left,0);
         int right = solve(root->right,1);

         return left+right;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return solve(root,-1);
    }
};