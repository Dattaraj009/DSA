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
    bool solve(TreeNode* root, int t,int c){
        if(!root) return false;
        
        if(c== t && !root->right && !root->left) return true;
        bool left = false;
        bool right = false;
        if(root->left) left = solve(root->left,t,c+root->left->val);
        if(root->right) right = solve(root->right,t,c+root->right->val);

        return left || right;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        return solve(root,targetSum,root->val);
    }
};